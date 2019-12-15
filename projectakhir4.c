#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

//Fungsi Prototype
void mainmenu();
void calculate();
void addmenu();
void displaymenu();
void displaymenu2();
void displaytotal();
void edit();
void reset();
void showtime();

//Struktur untuk menu item
typedef struct
{
    int code; //code item
    int price;
    char name[100];
} menu;

typedef struct
{
    char name2[100];
    int quantity;
    int total3;
} history;

menu item; //deklarasi item dengan struktur menu
history sell; //deklarasi sell dengan struktur history

//fungsi tampilan login
void login()
{
    int count = 0;
    system("cls");
    do
    {
        char uname[10], password[10];
        printf("\n\t\t====================== PLEASE LOGIN ======================");
        printf("\n\n\t\t\t\tEnter Username : ");
        scanf("%s", uname);
        printf("\n\n\t\t\t\tEnter Password : ");
        scanf("%s", password);
        if (strcmp(uname, "user") == 0 && strcmp(password, "pass") == 0)
        {
            printf("\n\n\t\t\t\t\tLogin Success");
            getch();
            system("cls");
            break;
        }
        else
        {
            printf("\n\t\t\t\tLogin Failed Please Reenter");
            getch();
            system("cls");
            count++;
        }
    } while (count < 3);
    if (count == 3)
    {
        printf("\n\n\n\n\n\t\t\tTelah memasukkan User dan Password yang salah sebanyak 3x, Program Berakhir");
        getch();
        exit(0);
    }
}

//Fungsi Utama
int main()
{
    login();
    mainmenu();
}

//Fungsi menu utama
void mainmenu()
{
    int choice, countArray;
    //list main menu    
    char *mainmenu[] = 
    {
        "                               ", 
        "Hitung                         ", 
        "Tambah Menu                    ", 
        "Tampilkan Daftar Menu          ", 
        "Tampilkan Total dan History    ",
        "Edit                           ",
        "Reset Total Pendapatan         ",
        "Keluar                         "
    };
    countArray = sizeof(mainmenu)/sizeof(mainmenu[0]);
    while(1){
        printf("\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
        for (int i = 1; i < countArray; i++)
        {
            printf("\t\t\t\t\xdb %d.%s\t\xdb\n\n", i, mainmenu[i]);
        }
        printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        printf("\n\n\t\t\t\tPilih Opsi : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            calculate();
            break;
        case 2:
            system("cls");
            addmenu();
            break;
        case 3:
            system("cls");
            displaymenu();
            break;
        case 4:
            system("cls");
            displaytotal();
            break;
        case 5:
            system("cls");
            edit();
            break;
        case 6:
            system("cls");
            reset();
            break;
        case 7:
            system("cls");
            break;
        default:
            printf("\n\n\t\t\t\t!!!Menu Tidak ada!!!");
            getch();
            system("cls");
            continue;
        }
        break;
    }
}

//Fungsi untuk menghitung tagihan
void calculate()
{
    int code, quantity, total, total2 = 0, money, change;
    char ulang;
    FILE *file, *file2;
    file = fopen("menulist11.txt", "r"); //buka file menulist11.txt untuk dibaca
    file2 = fopen("history.txt", "a+"); //buka file history.txt untuk ditulis
    do{
        system("cls");
        displaymenu2(); //panggil fungsi displaymenu2
        while (1)
        {
            printf("\n\n\t\t\t\tMasukkan Code Item : ");
            scanf("%d", &code);
            if (code == 0)
                break; //keluar while loop
            else if (code == 100)
                break; //keluar while loop
            printf("\t\t\t\tMasukkan jumlah : ");
            scanf("%d", &quantity);
            rewind(file);
            while (fread(&item, sizeof(item), 1, file))
            {
                if (item.code == code)
                {
                    total = item.price * quantity;
                    printf("\n\t\t\t\t%s %d = Rp. %d", item.name, quantity, total);
                    strcpy(sell.name2, item.name);
                    sell.quantity = quantity;
                    sell.total3 = total;
                    fwrite(&sell, sizeof(sell), 1, file2);
                    total2 = total2 + total;
                    break;
                }
            }
        }
        if (code == 100)
            break; //keluar do-while loop
        printf("\n\t\t\t\t=============Total = %d=============", total2);
        printf("\n\n\t\t\t\tMasukkan jumlah uang pelanggan : Rp. ");
        scanf("%d", &money);
        change = money - total2;
        printf("\n\t\t\t\t=========Kembalian : Rp. %d=========", change);
        total = 0, total2 = 0;
        printf("\n\n\t\t\t\tHitung Lagi (y/n) ? ");
        scanf(" %c", &ulang);
    }while(ulang == 'y' | ulang == 'Y');
    fclose(file);
    fclose(file2);
    printf("\n\n\t\t\t\tTekan apa saja untuk kembali ke menu utama. . .");
    getch();
    system("cls");
    mainmenu();
}

//fungsi untuk menambah menu item
void addmenu()
{
    char add;
    FILE *file;
    file = fopen("menulist11.txt", "a+"); //buka file menulist11.txt untuk ditulis
    while (1)
    {
        printf("\n\t\t\t\t masukkan \"0\" pada code item atau harga, atau \n\t\t\t\t\"batalkan\" pada nama item untuk membatalkan");
        printf("\n\n\n\t\t\t\t==================== Masukkan Code Item ====================");
        printf("\n\t\t\t\t> ");
        scanf("%d", &item.code);
        if (item.code == 0)
            break;
        fflush(stdin);
        printf("\n\n\t\t\t\t==================== Masukkan Nama Item ====================");
        printf("\n\t\t\t\t> ");
        gets(item.name);
        if (strcmp(item.name, "batalkan") == 0)
            break;
        printf("\n\n\t\t\t\t==================== Masukkan Harga Item ====================");
        printf("\n\t\t\t\t> ");
        scanf("%d", &item.price);
        if (item.price == 0)
            break;
        fwrite(&item, sizeof(item), 1, file);
        printf("\n\n\t\t\t\tTambah item lagi (Y/N) ? ");
        add = getch();
        if (add == 'n' || add == 'N')
            break;
        else
            system("cls");
    }
    fclose(file);
    printf("\n\t\t\t\tTekan apa saja untuk kembali ke Menu utama. . .");
    getch();
    system("cls");
    mainmenu();
}
//Fungsi untuk menampilkan semua daftar menu: Kode item, Nama Item, dan Harga
void displaymenu()
{
    FILE *file;
    file = fopen("menulist11.txt", "r");
    printf("\t\tCode Item\t\tNama Item\t\t\tHarga\n");
    printf("\t\t______________________________________________________________________");
    while (fread(&item, sizeof(item), 1, file))
    {
        printf("\n\t\t%d\t\t\t", item.code);
        printf("%s\t\t", item.name);
        if (strlen(item.name) < 8)
            printf("\t\t");
        else if (strlen(item.name) < 15)
            printf("\t");
        printf("%d ( %dK )", item.price, item.price/1000);
        printf("\n\t\t______________________________________________________________________");
    }

    // printf("\n");
    fclose(file);
    printf("\n\n\n\n\t\tTekan apa saja untuk kembali ke menu utama. . .");
    getch();
    system("cls");
    mainmenu();
}

//Fungsi untuk menampilkan daftar menu dalam fungsi calculate
void displaymenu2()
{
    FILE *file;
    file = fopen("menulist11.txt", "r");
    printf("\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\t\t\t\t\xdb\tCode Item\tNama Item\t\t\xdb\n");
    while (fread(&item, sizeof(item), 1, file))
    {
        printf("\n\t\t\t\t\xdb\t%d\t\t", item.code);
        printf("%s\t", item.name);
        if (strlen(item.name) < 8) 
            printf("\t\t\xdb\n"); //merapikan tulisan saat ditampilkan
        else if(strlen(item.name) < 15)
            printf("\t\xdb\n");
        else
            printf("\xdb\n");
    }
    printf("\n\t\t\t\t\xdb\tMasukkan \"0\" untuk hitung total\t\t\xdb");
    printf("\n\t\t\t\t\xdb\tMasukkan \"100\" untuk keluar\t\t\xdb");
    printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n");
    fclose(file);
}

//Fungsi untuk menampilkan pendapatan dari setiap pelanggan
void displaytotal()
{
    FILE *file2;
    int total_sell = 0, total_quantity = 0;
    file2 = fopen("history.txt", "r"); //buka file history.txt untuk dibaca
    // showtime();
    printf("\n\t\t\tNama Item\t\tJumlah\t\tTotal\n");
    rewind(file2);
    while (fread(&sell, sizeof(sell), 1, file2))
    {
        printf("\n\t\t\t%s\t", sell.name2);
        if (strlen(sell.name2) < 8)
            printf("\t\t");
        else if (strlen(sell.name2) < 15)
            printf("\t");
        printf("%d\t=\tRp. %d ( %dK )", sell.quantity, sell.total3, sell.total3/1000);
        total_sell += sell.total3;
        total_quantity += sell.quantity;
    }
    printf("\n\n\t\t\t======================================================");
    printf("\n\n\t\t\tTotal item\t\t%d\t=\tRp. %d ( %dK )",total_quantity, total_sell, total_sell/1000);
    fclose(file2);
    printf("\n\n\n\n\n\t\t\tTekan apa saja untuk kembali ke menu utama. . .");
    getch();
    system("cls");
    mainmenu();
}

//fungsi untuk mengedit item
void edit()
{
    system("cls");
    FILE *file;
    char edit;
    int x, choice, size;
    printf("\n\n\t\t\t\t=============EDIT MENU ITEM=============");
    printf("\n\n\t\t\t\tMasukkan code item yang ingin diedit: ");
    scanf("%d", &x);
    file=fopen("menulist11.txt","r+b");
    rewind(file);
    while (fread(&item,sizeof (item),1,file))
    {
        if(item.code == x)
        {
            printf("\n\n\n\t\t\t\tnama\t\t= %s",item.name);
            printf("\n\t\t\t\tcode\t\t= %d",item.code);
            printf("\n\t\t\t\tHarga\t\t= %d",item.price);
            printf("\n\n\n\t\t\t\tEdit Menu ini (Y/N) ? ");
            scanf(" %c", &edit);
            if (edit == 'y' || edit == 'Y')
            {
                system("cls");
                printf("\n\t\t\t\t1- Edit Nama ");
                printf("\n\n\t\t\t\t2- Edit Code ");
                printf("\n\n\t\t\t\t3- Edit Harga ");
                printf("\n\n\t\t\t\tPilih Opsi : ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                        printf("\n\n\t\t\t\tEdit Item");
                        printf("\n\n\t\t\t\tMasukkan nama baru : ");
                        scanf("%s",item.name);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    case 2:
                        printf("\n\n\t\t\t\tEdit Item");
                        printf("\n\n\t\t\t\tMasukkan code baru : ");
                        scanf("%d",item.code);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                    case 3:
                        printf("\n\n\t\t\t\tEdit Item");
                        printf("\n\n\t\t\t\tMasukkan harga baru: ");
                        scanf("%d",&item.price);
                        size=sizeof(item);
                        fseek(file,-size,SEEK_CUR);
                        fwrite(&item,sizeof(item),1,file);
                        break;
                }
                printf("\n\n\n\n\n\t\t\t\t---Item diedit---");
                getch();
                break;
            }
        }
    }
    fclose(file);
    system("cls");
    mainmenu();
}

//Fungsi untuk mereset jumlah pendapatan dan total pendapatan
void reset()
{
    char reset[10];
    printf("\n\n\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\n\n\t\t\t\t\tReset data (ketik \"reset\" untuk reset)");
    printf("\n\n\t\t\t\t\tketik \"batalkan\" untuk membatalkan");
    printf("\n\n\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\n\t\t\t\t\t> ");
    scanf("%s", reset);
    if (strcmp(reset, "reset") == 0)
    {
        remove("history.txt");
        printf("\n\n\t\t\t\t!!!!!!!!!!!!!!!!!---DATA DIRESET---!!!!!!!!!!!!!!!!!");
        printf("\n\n\t\t\t\tTekan apa saja untuk kembali ke menu utama. . . ");
        getch();
        system("cls");
        mainmenu();
    }
    else if (strcmp(reset, "batalkan") == 0){
        system("cls");
        mainmenu();
    }
    else{
        printf("\n\n\t\t\t\t\tOpsi tidak ada!");
        getch();
        system("cls");
        mainmenu();
    }
}

void showtime()
{
    char date[100];
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    printf ("\n\n\t\t\tTanggal dan waktu : %s", asctime(timeinfo));
}