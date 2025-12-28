#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menugetir();
void islemal(int secim);
void dosyayayazdir(char *mesaj, char *detay);
void rezervasyonYap();
void rezervasyonIptalEt();
void rezervasyonErtele();
void rezervasyonRevizeEt();
char *menu[] = {"1.Rezervasyon yap.","2.Rezervasyon iptal et.","3.Rezervasyon ertele.","4.Rezervasyon revize et."};
int secim[] = {1,2,3,4};

void menugetir() 
{
	int i=0;
    printf("OTEL REZERVASYON SISTEMI\n");
    for(i=0;i<4;i++)
	{
	printf("%s\n",menu[i]);
    }
    printf("Islem seciniz:");
}
void islemal(int secim) 
{
    if(secim==1) 
	{
        rezervasyonYap();
    }
    else if(secim==2) 
	{
        rezervasyonIptalEt();
    }
    else if(secim==3) 
	{
        rezervasyonErtele();
    }
    else if(secim==4) 
	{
        rezervasyonRevizeEt();
    }
    else 
	{
        printf("Seciminiz gecersiz!\n");
    }
}
void dosyayayazdir(char *islem, char *detay) 
{
    FILE *dosya = fopen("kayit.txt", "a");
	if (dosya == NULL) 
	{
        printf("Dosya acilamadi!\n");
        return;
	}
    fprintf(dosya, "Islem:%s Detay:%s\n",islem,detay);
    fclose(dosya);
    printf("'kayit.txt' dosyasina kaydedildi.\n");
}
void rezervasyonYap() 
{
    char adSoyad[50];
    char tc[12];
    char telefonno[15];
    char tumbilgiler[150];
    printf("Rezervasyon Olustur\n");
    printf("Adinizi ve Soyadinizi giriniz:");
	getchar();
	fgets(adSoyad,50,stdin);
	printf("TC Kimlik Numaranizi giriniz:");
    scanf("%s",tc);
    printf("Telefon Numaranizi giriniz:");
    scanf("%s",telefonno);
	printf("Rezervasyonunuz alindi!\n");
	strcpy(tumbilgiler, adSoyad);
    strcat(tumbilgiler, " TC:");
    strcat(tumbilgiler, tc);
    strcat(tumbilgiler, " Telefon numarasi:");
    strcat(tumbilgiler, telefonno);
    dosyayayazdir("YENI REZERVASYON",tumbilgiler);
}
void rezervasyonIptalEt() 
{
    char adSoyad[50];
    printf("Rezervasyon Iptal\n");
    printf("Adinizi ve Soyadinizi giriniz:");
	getchar();
	fgets(adSoyad,50,stdin);
    printf("Rezervasyonunuz iptal edildi!\n");
    dosyayayazdir("IPTAL ISLEMI",adSoyad);
}
void rezervasyonErtele() 
{
    printf("Rezervasyon Erteleniyor.\n");
    dosyayayazdir("ERTELEME", "Menuden ertelemeyi secildi");
}
void rezervasyonRevizeEt() 
{
    printf("Rezervasyon Revize ediliyor.\n");
    dosyayayazdir("REVIZE", "Menuden revizeyi secildi");
}
int main() 
{
    int secim;
	menugetir();
    scanf("%d", &secim); 
	islemal(secim);
	return 0;
}
