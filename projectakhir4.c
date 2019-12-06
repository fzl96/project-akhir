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

//Structur untuk menu
typedef struct
{
    int code;
    int price;
    char name[100];
} menu;

//structur pendapatan
typedef struct
{
    int total;
} price;

price harga;
menu item;

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

//Fungsi tampilan menu utama
void mainmenu()
{
    int choice;
    printf("\n\n\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\t\t\t\xdb\t                                   \t\xdb");
    printf("\n\t\t\t\xdb\t1. Hitung                          \t\xdb");
    printf("\n\t\t\t\xdb\t                                   \t\xdb");
    printf("\n\t\t\t\xdb\t2. Tambah Menu                     \t\xdb");
    printf("\n\t\t\t\xdb\t                                   \t\xdb");
    printf("\n\t\t\t\xdb\t3. Tampilkan Daftar Menu           \t\xdb");
    printf("\n\t\t\t\xdb\t                                   \t\xdb");
    printf("\n\t\t\t\xdb\t4. Tampilkan pendapatan per-order  \t\xdb");
    printf("\n\t\t\t\xdb\t                                   \t\xdb");
    printf("\n\t\t\t\xdb\t5. Tampilkan Total pendapatan      \t\xdb");
    printf("\n\t\t\t\xdb\t                                   \t\xdb");
    printf("\n\t\t\t\xdb\t6. Reset Total Pendapatan          \t\xdb");
    printf("\n\t\t\t\xdb\t                                   \t\xdb");
    printf("\n\t\t\t\xdb\t7. Keluar                          \t\xdb");
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
        totalearn();
        break;
    case 6:
        system("cls");
        reset();
        break;
    case 7:
        system("cls");
        break;
    default:
        system("cls");
        printf("\n\n\n\t\t\t\t\t!!!Menu Tidak ada!!!");
        break;
    }
}

//Fungsi untuk menghitung tagihan
void calculate()
{
    int code, quantity, total, total2 = 0, money, change;
    char ulang;
    FILE *file, *file2;
    file = fopen("menulist11.txt", "r");
    file2 = fopen("total.txt","a+");
    do{
        displaymenu2();
        while (1)
        {
            printf("\n\n\t\t\t\tMasukkan Code Item : ");
            scanf("%d", &code);
            if (code == 0)
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
                    total2 = total2 + total;
                    break;
                }
            }
        }
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
        system("cls");
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
    char x, add;
    FILE *file;
    file = fopen("menulist11.txt", "a+");
    while (1)
    {
        printf("\n\t\t\t\t masukkan \"0\" pada code item atau \n\t\t\t\t\"batalkan\" pada nama item untuk membatalkan");
        printf("\n\n\n\t\t\t\t==================== Masukkan Code Item ====================");
        printf("\n\t\t\t\t> ");
        scanf("%d", &item.code);
        if (item.code == 0){
            system("cls");
            mainmenu();
        }
        fflush(stdin);
        printf("\n\n\t\t\t\t==================== Masukkan nama Item ====================");
        printf("\n\t\t\t\t> ");
        gets(item.name);
        if (strcmp(item.name, "batalkan") == 0){
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
    printf("Code Item\t\tNama Item\t\t\tHarga\n");
    while (fread(&item, sizeof(item), 1, file))
    {
        printf("\n%d\t\t\t", item.code);
        printf("%s\t\t\t", item.name);
        printf("%d", item.price);
    }

    printf("\n");
    fclose(file);
    printf("\n\nTekan apa saja untuk kembali ke menu utama. . .");
    getch();
    system("cls");
    mainmenu();
}

//Fungsi untuk menampilkan daftar menu dalam fungsi calculate
void displaymenu2()
{
    FILE *file;
    file = fopen("menulist11.txt", "r");
    printf("\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\t\t\t\xdb\tCode Item\t\tNama Item\t\xdb");
    while (fread(&item, sizeof(item), 1, file))
    {
        printf("\n\n\t\t\t\xdb\t%d\t\t\t", item.code);
        printf("%s\t\xdb", item.name);
    }
    printf("\n");
    printf("\n\t\t\t\xdb\tMasukkan \"0\" untuk tampilkan total\t\xdb");
    printf("\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    fclose(file);
}

//Fungsi untuk menampilkan pendapatan dari setiap pelanggan
void displaytotal()
{
    FILE *file2;
    file2 = fopen("total.txt","r");
    while (fread(&harga, sizeof(harga), 1, file2))
    {
        printf("\n\t\t\t\tPendapatan : Rp. %d", harga.total);
    }
    printf("\n");
    fclose(file2);
    printf("\n\n\t\t\tTekan apa saja untuk kembali ke menu utama. . .");
    getch();
    system("cls");
    mainmenu();
}

//Fungsu untuk menampilkan jumlah pendapatan dari seluruh pelanggan yang telah dihitung
void totalearn()
{
    int total_pendapatan = 0;
    FILE *file2;
    file2 = fopen("total.txt","r");
    while (fread(&harga, sizeof(harga), 1, file2))
    {
        total_pendapatan = total_pendapatan + harga.total;
    }
    showtime();
    printf("\n\n\t\t\t\t======Total Pendapatan Sejauh ini adalah: Rp. %d======", total_pendapatan);
    fclose(file2);
    printf("\n\n\n\t\t\t\tTekan apa saja untuk kembali ke menu utama. . .");
    getch();
    system("cls");
    mainmenu();
}

//Fungsi untuk mereset jumlah pendapatan dan total pendapatan
void reset()
{
    FILE *file2, *file3;
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
        printf("\n\n\t\t\t\t!!!!!!!!!!!!!!!!!---DATA DI RESET---!!!!!!!!!!!!!!!!!");
        //file3 = fopen("total2.txt","ab");
        //rename("total2.txt","total.txt");
        //fclose(file3);
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
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);
  printf ("\n\n\t\t\t\tTanggal dan waktu : %s", asctime(timeinfo));
}