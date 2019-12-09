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
void totalearn();
void reset();
void showtime();

//Struktur untuk menu
typedef struct
{
    int code;
    int price;
    char name[100];
} menu;

//struktur pendapatan
typedef struct
{
    int total;
} price;

//struktur untuk history
typedef struct
{
    char name2[100];
    int quantity;
    int total3;
} history;

price harga;
menu item;
history sell;

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
        scanf("%s", &uname);
        printf("\n\n\t\t\t\tEnter Password : ");
        scanf("%s", &password);

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
    while(1){
        int choice;
        printf("\n\n\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        printf("\n\t\t\t\xdb\t                                   \t\xdb");
        printf("\n\t\t\t\xdb\t1. Hitung                          \t\xdb");
        printf("\n\t\t\t\xdb\t                                   \t\xdb");
        printf("\n\t\t\t\xdb\t2. Tambah Menu                     \t\xdb");
        printf("\n\t\t\t\xdb\t                                   \t\xdb");
        printf("\n\t\t\t\xdb\t3. Tampilkan Daftar Menu           \t\xdb");
        printf("\n\t\t\t\xdb\t                                   \t\xdb");
        printf("\n\t\t\t\xdb\t4. Tampilkan Total dan History     \t\xdb");
        printf("\n\t\t\t\xdb\t                                   \t\xdb");
        printf("\n\t\t\t\xdb\t5. Reset Total Pendapatan          \t\xdb");
        printf("\n\t\t\t\xdb\t                                   \t\xdb");
        printf("\n\t\t\t\xdb\t6. Keluar                          \t\xdb");
        printf("\n\t\t\t\xdb\t                                   \t\xdb");
        printf("\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
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
            reset();
            break;
        case 6:
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
    FILE *file, *file2, *file3;
    file = fopen("menulist11.txt", "r");
    file2 = fopen("total.txt","a+");
    file3 = fopen("history.txt", "ab");
    do{
        system("cls");
        displaymenu2();
        while (1)
        {
            printf("\n\n\t\t\t\tMasukkan Code Item : ");
            scanf("%d", &code);
            if (code == 0)
                break;
            else if (code == 100)
                break;
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
                    fwrite(&sell, sizeof(sell), 1, file3);
                    total2 = total2 + total;
                    break;
                }
            }
        }
        if (code == 100)
            break;
        printf("\n\t\t\t\t=============Total = %d=============", total2);
        printf("\n\n\t\t\t\tMasukkan jumlah uang pelanggan : Rp. ");
        scanf("%d", &money);
        change = money - total2;
        printf("\n\t\t\t\t=========Kembalian : Rp. %d=========", change);
        harga.total = total2;
        total = 0, total2 = 0;
        fwrite(&harga, sizeof(harga), 1, file2);
        printf("\n\n\t\t\t\tHitung Lagi (y/n) ? ");
        scanf(" %c", &ulang);
    }while(ulang == 'y' | ulang == 'Y');

    fclose(file);
    fclose(file2);
    fclose(file3);
    printf("\n\n\t\t\t\tTekan apa saja untuk kembali ke menu utama. . .");
    getch();
    system("cls");
    mainmenu();
}

//fungsi untuk menambah menu item
void addmenu()
{
    char x, add;
    FILE *file;
    file = fopen("menulist11.txt", "a+");
    while (1)
    {
        printf("\n\t\t\t\t masukkan \"0\" pada code item atau \n\t\t\t\t\"batalkan\" pada nama item untuk membatalkan");
        printf("\n\n\n\t\t\t\t==================== Masukkan Code Item ====================");
        printf("\n\t\t\t\t> ");
        scanf("%d", &item.code);
        if (item.code == 0)
        {
            system("cls");
            mainmenu();
        }
        fflush(stdin);
        printf("\n\n\t\t\t\t==================== Masukkan nama Item ====================");
        printf("\n\t\t\t\t> ");
        gets(item.name);
        if (strcmp(item.name, "batalkan") == 0)
        {
            system("cls");
            mainmenu();
        }
        printf("\n\n\t\t\t\t==================== Masukkan Harga Item ====================");
        printf("\n\t\t\t\t> ");
        scanf("%d", &item.price);
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
    printf("\t\tCode Item\t\tNama Item\t\tHarga\n");
    printf("\t\t______________________________________________________________");
    while (fread(&item, sizeof(item), 1, file))
    {
        printf("\n\t\t%d\t\t\t", item.code);
        printf("%s\t\t", item.name);
        if (strlen(item.name) < 8)
            printf("\t");
        printf("%d ( %dK )", item.price, item.price/1000);
        printf("\n\t\t______________________________________________________________");
    }

    printf("\n");
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
    printf("\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\t\t\t\t\xdb\tCode Item\tNama Item\t\xdb\n");
    while (fread(&item, sizeof(item), 1, file))
    {
        printf("\n\t\t\t\t\xdb\t%d\t\t", item.code);
        printf("%s\t", item.name);
        if (strlen(item.name) < 8)
            printf("\t\xdb\n");
        else
            printf("\xdb\n");
    }
    printf("\n\t\t\t\t\xdb    Masukkan \"0\" untuk hitung total\t\xdb");
    printf("\n\t\t\t\t\xdb    Masukkan \"100\" untuk keluar\t\xdb");
    printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n");
    fclose(file);
}

//Fungsi untuk menampilkan pendapatan dari setiap pelanggan
void displaytotal()
{
    FILE *file2, *file3;
    int total_sell = 0, total_quantity = 0;
    file2 = fopen("total.txt","r");
    file3 = fopen("history.txt", "r");
    showtime();
    printf("\n\t\t\tNama Item\tJumlah\t\tTotal\n");
    rewind(file3);
    while (fread(&sell, sizeof(sell), 1, file3))
    {
        printf("\n\t\t\t%s\t", sell.name2);
        if (strlen(sell.name2) < 8)
            printf("\t");
        printf("%d\t=\tRp. %d ( %dK )", sell.quantity, sell.total3, sell.total3/1000);
        total_sell += sell.total3;
        total_quantity += sell.quantity;
    }
    printf("\n\n\t\t\t======================================================");
    printf("\n\n\t\t\tTotal item\t%d\t=\tRp. %d ( %dK )",total_quantity, total_sell, total_sell/1000);
    fclose(file3);
    fclose(file2);
    printf("\n\n\n\n\n\t\t\tTekan apa saja untuk kembali ke menu utama. . .");
    getch();
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
        remove("total.txt");
        remove("history.txt");
        printf("\n\n\t\t\t\t!!!!!!!!!!!!!!!!!---DATA DI RESET---!!!!!!!!!!!!!!!!!");
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