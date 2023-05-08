
/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: 1.proje(güz proje)
**				ÖĞRENCİ ADI...............:  ATAKAN
**				ÖĞRENCİ NUMARASI.: G201210054
**				DERS GRUBU…………: 2.ÖĞRETİM C GRUBU
****************************************************************************/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <locale.h>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
using namespace std;

struct urunler
{

	int urunkodu = 0;								//ürünler dosasi icin olusturdugumuz struct
	string urun_adi;
	string urun_uretici;
	string temin_sure;
	string tarih;
	float fiyat = 0;
	float fiyat_ozel = 0;
	float kdv = 0;
	int stokaded = 0;

};
struct musteri                                      //müsteri dosyasi icin olusturdugumuz struct
{
	int firmano;
	string firmaad;
	string firmatel;
	string firma_sor;
	string katagori;
	string adres;
};




int main()
{

	setlocale(LC_ALL, "Turkish");
	musteri müşteri;
	urunler urun;



	int Firmano;                   //siparis listesi icin tanimladiklarimiz
	string siptar;
	int siptut = 0;
	string sipalan;
	int Urunkod;
	int Sipaded;



	string arama;                //arama islemi icin
	int secim;                   //kullanicidan alinacak sayi icin
	char durum;                  //dongunun durumunu belirlemek icin
	do
	{
		cout << " Yapmak istediğiniz işlemi seçiniz" << endl;
		cout << " Ürün için işlemler (1)" << endl;
		cout << " Müşteri dosyası işlemleri(2)" << endl;
		cout << " Sipariş işlemleri için(3)" << endl;
		cout << " Programdan cikis (4)" << endl;
		cin >> secim;
		if (secim == 1)                    //secmin 1 oldugu icin urun icin islemler yapilacak
		{
			int secim1;

			do
			{
				cout << " Ürün için yapmak istediğiniz işlem" << endl;          // kullanicidan ne yapmak istedigini aliyoruz
				cout << " Ürün ekleme(1)" << endl;
				cout << " Ürün arama(2)" << endl;
				cout << " Ürün listeleme(3)" << endl;
				cout << " Ürün düzeltme(4)" << endl;
				cout << " Ürün silme(5)" << endl;
				cin >> secim1;

				if (secim1 == 1)               //urun ekleme islemleri
				{
					char tekrar;
					ofstream Dosyayaz("urunler.txt", ios::app);               //Dosyayi append modda aciyoruz
					do {

						cout << "Ürünün kodu:"; cin >> urun.urunkodu;                 //kullanicidan gerekli bilgileri aliyoruz

						cout << "Ürün Adı:    (Lütfen boşluk kullanmayiniz örn: AtakanPasali)";
						getline(cin >> ws, urun.urun_adi);

						cout << "Üretici:"; getline(cin >> ws, urun.urun_uretici);            //getline kullaniyoruz aksi taktirde entera basildiginda onu da bilgi olarak kabul edip diger satira geciyor

						cout << "Temin süresi:"; getline(cin >> ws, urun.temin_sure);

						cout << "Üretim tarihi:"; getline(cin >> ws, urun.tarih);
						cout << "Fiyat:"; cin >> urun.fiyat;
						cout << "Özel fiyat:"; cin >> urun.fiyat_ozel;
						cout << "Kdv oranı:"; cin >> urun.kdv;
						cout << "stok adedi:"; cin >> urun.stokaded;

						Dosyayaz << urun.urunkodu << ' ' << urun.urun_adi << ' ' << urun.urun_uretici << ' ' << urun.temin_sure << ' ' << urun.tarih << ' ' << urun.fiyat << ' ' << urun.fiyat_ozel << ' '
							<< urun.kdv << ' ' << urun.stokaded << "\n";  //dosyaya yazdirma islemleri

						cout << "Başka ürün eklemek ister misiniz e/h";
						cin >> tekrar;                       //baska urun eklemeyi istedigini veya istemedigini konrol ediyoruz
					} while (tekrar == 'e');
					Dosyayaz.close();            //Dosyayi kapatiyoruz
					cout << "ürün ekleme basariyla tamamlandı" << endl;
				}
				if (secim1 == 2)
				{
					int arama;
					cout << "Aramak istediğiniz ürünün kodunu giriniz" << endl;       //arama islemleri icin
					cin >> arama;                                     //urunu koduna gore ariyoruz. Kullanicidan aramak istedigi urunun kodunu aliyoruz
					ifstream Dosyaoku("urunler.txt", ios::app);   //dosya okuma islemleri icin urunler.txt yi okuma modunda aciyoruz

					while (Dosyaoku >> urun.urunkodu >> urun.urun_adi >> urun.urun_uretici >> urun.temin_sure >> urun.tarih >> urun.fiyat >> urun.fiyat_ozel >> urun.kdv >> urun.stokaded)
					{


						if (arama == urun.urunkodu)      //eger aranan kod urunun kodu ile uygun ise aradigimiz kodda urun geliyor.
						{
							cout << "Ürün kodu: " << urun.urunkodu << endl;
							cout << "Ürün Adı: " << urun.urun_adi << endl;
							cout << "Üretici: " << urun.urun_uretici << endl;
							cout << "Temin Süresi :" << urun.temin_sure << endl;
							cout << "Fiyatı :" << urun.fiyat << endl;
							cout << "Stok adedi:" << urun.stokaded << endl;
						}

						cout << endl;

					}



					cout << endl;

					Dosyaoku.close();
				}

				if (secim1 == 3)              //listeleme icin kullaniyoruz
				{
					string girdi;
					int sec;
					cout << "lütfen listelemek istediğiniz ürünün adını giriniz: ";     //listelemek istedigimiz urunun adini giriyoruz 
					getline(cin >> ws, girdi);
					cout << "Neye göre listeleme yapmak istersiniz?" << endl;           // burasi sayesinde adi ayni olan urunleri teker teker listeleyebiliyoruz 
					cout << "Fiyata göre(1)" << endl;                                   // bir fiyat araligi giriyoruz ve o fiyat araligindaki urunleri gosteriyor
					cout << "Üreticiye göre(2)" << endl;                                // urunu kimin urettigine gore listelemeyi yapiyor
					cout << "Koda göre(3)" << endl;                                     //urunun koduna gore buluyor
					cin >> sec;
					if (sec == 1)                     //fiyata gore 
					{
						int fiyat1, fiyat2;
						cout << "Bir fiyat aralığı girin";   //fiyat aralıgı aliyoruz
						cin >> fiyat1;
						cin >> fiyat2;
						ifstream Dosyaoku("urunler.txt");
						while (Dosyaoku >> urun.urunkodu >> urun.urun_adi >> urun.urun_uretici >> urun.temin_sure >> urun.tarih >> urun.fiyat >> urun.fiyat_ozel >> urun.kdv >> urun.stokaded)
						{

							if (girdi == urun.urun_adi)                                        // sadece listeleme isleminin en basinda girilen urun adiyla uygun urunleri kontrol etmek icin kullaniliyor
							{
								if (urun.fiyat >= fiyat1 && urun.fiyat <= fiyat2)              //urunun girilen aralikta olup olmadigi kontrol ediliyor eger oyleyse urun bilgileri yazdiriliyor
								{
									cout << "Ürün kodu: " << urun.urunkodu << endl;
									cout << "Ürün Adı: " << urun.urun_adi << endl;
									cout << "Üretici: " << urun.urun_uretici << endl;
									cout << "Temin Süresi :" << urun.temin_sure << endl;
									cout << "Fiyatı :" << urun.fiyat << endl;
									cout << "Stok adedi:" << urun.stokaded << endl;
								}
							}
							cout << endl;

						}
						Dosyaoku.close();
					}
					if (sec == 2)                 //ureticiye gore
					{
						string üretici;
						cout << "Lütfen bir üretici giriniz:";
						getline(cin >> ws, üretici);
						ifstream Dosyaoku("urunler.txt");
						while (Dosyaoku >> urun.urunkodu >> urun.urun_adi >> urun.urun_uretici >> urun.temin_sure >> urun.tarih >> urun.fiyat >> urun.fiyat_ozel >> urun.kdv >> urun.stokaded)
						{

							if (girdi == urun.urun_adi)
							{
								if (üretici == urun.urun_uretici)   //girilen ureticinin urunun ureticisiyle eslesip eslesmedigi kontrol ediliyor eger oyleyse urun ekrana yazdiriliyor
								{
									cout << "Ürün kodu: " << urun.urunkodu << endl;
									cout << "Ürün Adı: " << urun.urun_adi << endl;
									cout << "Üretici: " << urun.urun_uretici << endl;
									cout << "Temin Süresi :" << urun.temin_sure << endl;
									cout << "Fiyatı :" << urun.fiyat << endl;
									cout << "Stok adedi:" << urun.stokaded << endl;
								}
								cout << endl;
							}
						}
						Dosyaoku.close();
					}
					if (sec == 3)     //koda gore
					{
						int girkod;
						cout << "Lütfen bir kod giriniz:";
						cin >> girkod;
						ifstream Dosyaoku("urunler.txt");
						while (Dosyaoku >> urun.urunkodu >> urun.urun_adi >> urun.urun_uretici >> urun.temin_sure >> urun.tarih >> urun.fiyat >> urun.fiyat_ozel >> urun.kdv >> urun.stokaded)
						{

							if (girdi == urun.urun_adi)
							{
								if (girkod == urun.urunkodu)                //girilen kodun urunun koduyla ayni olup oladigi kontrol ediliyor eger oyleyse urun yazdiriliyor
								{
									cout << "Ürün kodu: " << urun.urunkodu << endl;
									cout << "Ürün Adı: " << urun.urun_adi << endl;
									cout << "Üretici: " << urun.urun_uretici << endl;
									cout << "Temin Süresi :" << urun.temin_sure << endl;
									cout << "Fiyatı :" << urun.fiyat << endl;
									cout << "Stok adedi:" << urun.stokaded << endl;
								}
								cout << endl;
							}
						}
						Dosyaoku.close();
					}
				}
				if (secim1 == 4) //urun duzeltmek icin
				{
					int düzelt;
					cout << "Lütfen düzeltmek istediğiniz ürünün kodunu giriniz:";
					cin >> düzelt;
					ifstream Dosyaoku("urunler.txt");                //urunler.txt den bilgileri okuyoruz
					ofstream Dosyayaz("urunler.tmp");                // bir tmp dosyasi olusturuyoruz
					while (Dosyaoku >> urun.urunkodu >> urun.urun_adi >> urun.urun_uretici >> urun.temin_sure >> urun.tarih >> urun.fiyat >> urun.fiyat_ozel >> urun.kdv >> urun.stokaded)
					{


						if (düzelt == urun.urunkodu)  //duzeltmek istedigimiz urunu buluyor ve bilgileri yeniden girmemizi sagliyor ve tmp dosyasina yaziyor
						{
							cout << "Kayıtlı ürün  :" << endl;
							cout << "Urun kodu     : " << urun.urunkodu << endl;
							cout << "Urun Adi      :" << urun.urun_adi << endl;
							cout << "Uretici       :" << urun.urun_uretici << endl;
							cout << "Temin sure    :" << urun.temin_sure << endl;
							cout << "Uretim Tarihi :" << urun.tarih << endl;
							cout << "Urun fiyati   :" << urun.fiyat << endl;
							cout << "Ozel fiyat    :" << urun.fiyat_ozel << endl;
							cout << "Kdv Orani     :" << urun.kdv << endl;
							cout << "Stok adedi    :" << urun.stokaded << endl;
							cout << "Düzeltme için yeni değerler:" << endl;
							cout << "Ürünün kodu:"; cin >> urun.urunkodu;
							cout << "Ürün Adı:";
							getline(cin >> ws, urun.urun_adi);
							cout << "Üretici:"; getline(cin >> ws, urun.urun_uretici);
							cout << "Temin süresi:"; getline(cin >> ws, urun.temin_sure);
							cout << "Üretim tarihi:"; getline(cin >> ws, urun.tarih);
							cout << "Fiyat:"; cin >> urun.fiyat;
							cout << "Özel fiyat:"; cin >> urun.fiyat_ozel;
							cout << "Kdv oranı:"; cin >> urun.kdv;
							cout << "stok adedi:"; cin >> urun.stokaded;

							Dosyayaz << urun.urunkodu << ' ' << urun.urun_adi << ' ' << urun.urun_uretici << ' ' << urun.temin_sure << ' ' << urun.tarih << ' ' << urun.fiyat << ' ' << urun.fiyat_ozel << ' '
								<< urun.kdv << ' ' << urun.stokaded << "\n";

						}

						else       //duzeltmek istedigimiz urunlerin disindaki urunleri direkt olarak tmp dosyasina kaydediyor
						{
							Dosyayaz << urun.urunkodu << ' ' << urun.urun_adi << ' ' << urun.urun_uretici << ' ' << urun.temin_sure << ' ' << urun.tarih << ' ' << urun.fiyat << ' ' << urun.fiyat_ozel << ' '
								<< urun.kdv << ' ' << urun.stokaded << "\n";
						}

					}
					Dosyayaz.close();  //dosyalari kapatiyoruz aksi taktirde remove ve rename islemleri calismaz
					Dosyaoku.close();
					remove("urunler.txt");             //urunler.txt dosyasini kaldiriyoruz
					rename("urunler.tmp", "urunler.txt");  //gecici dosyayi ana txt dosyasi haline ceviriyoruz
				}
				if (secim1 == 5)          //silmek istedigimiz urunler icin
				{
					int sil;
					cout << "Lütfen silmek istediğiniz ürünün kodunu giriniz:";  //kullanicidan silinmek istenen urun kodu aliniyor
					cin >> sil;
					ifstream Dosyaoku("urunler.txt");
					ofstream Dosyayaz("urunler.tmp");
					while (Dosyaoku >> urun.urunkodu >> urun.urun_adi >> urun.urun_uretici >> urun.temin_sure >> urun.tarih >> urun.fiyat >> urun.fiyat_ozel >> urun.kdv >> urun.stokaded)
					{


						if (sil == urun.urunkodu)  //urunlerin kodlarini eslestiriyoruz. Eslesen urun hakkinda herhangi bir dosya islemi yapmiyoruz
						{
							cout << "Silinmek istenen ürün" << endl;
							cout << "Urun kodu     : " << urun.urunkodu << endl;
							cout << "Urun Adi      :" << urun.urun_adi << endl;
							cout << "Uretici       :" << urun.urun_uretici << endl;
							cout << "Temin sure    :" << urun.temin_sure << endl;
							cout << "Uretim Tarihi :" << urun.tarih << endl;
							cout << "Urun fiyati   :" << urun.fiyat << endl;
							cout << "Ozel fiyat    :" << urun.fiyat_ozel << endl;
							cout << "Kdv Orani     :" << urun.kdv << endl;
							cout << "Stok adedi    :" << urun.stokaded << endl;
						}

						else      //diger bilgileri tmp dosyasina kaydediyoruz
						{
							Dosyayaz << urun.urunkodu << ' ' << urun.urun_adi << ' ' << urun.urun_uretici << ' ' << urun.temin_sure << ' ' << urun.tarih << ' ' << urun.fiyat << ' ' << urun.fiyat_ozel << ' '
								<< urun.kdv << ' ' << urun.stokaded << "\n";
						}
					}
					Dosyayaz.close();
					Dosyaoku.close();
					remove("urunler.txt");
					rename("urunler.tmp", "urunler.txt");
				}
			} while (secim1 != 1 && secim1 != 2 && secim1 != 3 && secim1 != 4 && secim1 != 5);
		}

		if (secim == 2)   //musteri islemleri 
		{
			int secim2;
			do
			{
				cout << "Yapmak istediğiniz işlemi giriniz" << endl; //kullanicidan yapmak istedigi islemi aliyoruz
				cout << "Müşteri ekleme(1)" << endl;
				cout << "Müşteri arama(2)" << endl;
				cout << "Müşteri düzeltme(3)" << endl;
				cout << "Müşteri silme(4)" << endl;
				cin >> secim2;

				if (secim2 == 1)   //musteri eklemek icin
				{
					char karar;
					ofstream Dosyayaz("cari.txt", ios::app);     //cari.txt olusturuyoruz
					do
					{
						cout << " Firma Numarası    : "; cin >> müşteri.firmano;          //bilgileri aliyoruz
						cout << " Firma Adı         : (Lutfen bosluk kullanmayiniz)"; getline(cin >> ws, müşteri.firmaad);
						cout << " Telefon Numarası  : "; getline(cin >> ws, müşteri.firmatel);
						cout << " Firma sorumlusu   : (Lütfen bosluk kullanmayiniz orn: AtakanPasali)"; getline(cin >> ws, müşteri.firma_sor);
						cout << " Müşteri katagorisi: "; getline(cin >> ws, müşteri.katagori);
						cout << " Müşteri Adresi    : "; getline(cin >> ws, müşteri.adres);
						Dosyayaz << müşteri.firmano << ' ' << müşteri.firmaad << ' ' << müşteri.firmatel << ' ' << müşteri.firma_sor << ' ' << müşteri.katagori << ' ' << müşteri.adres << '\n';
						cout << endl;
						cout << "Başka müşteri eklemek ister misiniz ? e/h";   //kullanicidan baska musteri ekleyip isteyip istemedini aliyoruz ever istiyorsa islemi tekrarliyoruz
						cin >> karar;
					} while (karar == 'e');
					Dosyayaz.close();
					cout << "Müşteri ekleme işlemi tamamlandı" << endl;

				}
				if (secim2 == 2)   //arama islemi icin
				{
					int neyegör;
					cout << " Neye göre arama yapmak istersiniz?" << endl;      //2 cesit arama yapilabiliyor
					cout << " (1)Firma numarasına göre" << endl;
					cout << " (2)Firma adına göre " << endl;
					cin >> neyegör;

					if (neyegör == 1)  //eger neyegor 1 ise firma numarasina gore ariyoruz
					{
						int numara;
						cout << "Lütfen aramak istediğiniz firma numarasını giriniz:";   //kullanicidan numarayi aliyoruz 
						cin >> numara;

						ifstream Dosyaoku1("cari.txt");

						while (Dosyaoku1 >> müşteri.firmano >> müşteri.firmaad >> müşteri.firmatel >> müşteri.firma_sor >> müşteri.katagori >> müşteri.adres)
						{

							if (numara == müşteri.firmano)
							{
								cout << " Firma Numarası    : " << müşteri.firmano << endl;
								cout << " Firma Adı         : " << müşteri.firmaad << endl;
								cout << " Telefon Numarası  :" << müşteri.firmatel << endl;
								cout << " Firma sorumlusu   : " << müşteri.firma_sor << endl;
								cout << " Müşteri katagorisi: " << müşteri.katagori << endl;
								cout << " Müşteri Adresi    : " << müşteri.adres << endl;

							}

							cout << endl;
						}

					}
					if (neyegör == 2) //eger neyegör 2 ise firma adina gore arama yapiyoruz
					{
						cout << "Lütfen aramak istediğiniz firma adını giriniz:";
						getline(cin >> ws, arama);

						ifstream Dosyaoku1("cari.txt");
						while (Dosyaoku1 >> müşteri.firmano >> müşteri.firmaad >> müşteri.firmatel >> müşteri.firma_sor >> müşteri.katagori >> müşteri.adres)
						{

							if (arama == müşteri.firmaad)
							{
								cout << " Firma Numarası    : " << müşteri.firmano << endl;
								cout << " Firma Adı         : " << müşteri.firmaad << endl;
								cout << " Telefon Numarası  : " << müşteri.firmatel << endl;
								cout << " Firma sorumlusu   : " << müşteri.firma_sor << endl;
								cout << " Müşteri katagorisi: " << müşteri.katagori << endl;
								cout << " Müşteri Adresi    : " << müşteri.adres << endl;

							}

							cout << endl;
						}

					}

				}
				if (secim2 == 3)  //musteri duzeltmek icin
				{
					char durum1;
					do
					{
						int düz;
						cout << "Lütfen düzeltmek istediğiniz firmanın kodunu giriniz " << endl;  // kullanicidan firmanin kodunu aliyoruz
						cin >> düz;
						ifstream dosyaoku1("cari.txt");    //cari.txt den bilgi okumak icin
						ofstream dosyaz1("cari.tmp");      //duzeltme islemi icin temporary dosya
						while (dosyaoku1 >> müşteri.firmano >> müşteri.firmaad >> müşteri.firmatel >> müşteri.firma_sor >> müşteri.katagori >> müşteri.adres)
						{


							if (düz == müşteri.firmano)  //girdigimiz kodla eslesen firma icin yeni bilgiler giriyoruz ve tmp dosyasina yaziyoruz
							{
								cout << "Düzeltmek istediğiniz firma:" << endl;
								cout << "Firma no       :" << müşteri.firmano << endl;
								cout << "Firma ad       :" << müşteri.firmaad << endl;
								cout << "Firma tel      :" << müşteri.firmatel << endl;
								cout << "Firma sorumlusu:" << müşteri.firma_sor << endl;
								cout << "Firma katagori :" << müşteri.katagori << endl;
								cout << "Firma adresi   :" << müşteri.adres << endl;

								cout << " Yeni bilgileri giriniz:" << endl;
								cout << " Firma Numarası    : "; cin >> müşteri.firmano;
								cout << " Firma Adı         : "; getline(cin >> ws, müşteri.firmaad);
								cout << " Telefon Numarası  :"; getline(cin >> ws, müşteri.firmatel);
								cout << " Firma sorumlusu   : "; getline(cin >> ws, müşteri.firma_sor);
								cout << " Müşteri katagorisi: "; getline(cin >> ws, müşteri.katagori);
								cout << " Müşteri Adresi    : "; getline(cin >> ws, müşteri.adres);
								dosyaz1 << müşteri.firmano << ' ' << müşteri.firmaad << ' ' << müşteri.firmatel << ' ' << müşteri.firma_sor << ' ' << müşteri.katagori << ' ' << müşteri.adres << '\n';
								cout << endl;

							}
							else  //diger musterileri firekt olarak tmp dosyasina yaziyoruz
							{

								dosyaz1 << müşteri.firmano << ' ' << müşteri.firmaad << ' ' << müşteri.firmatel << ' ' << müşteri.firma_sor << ' ' << müşteri.katagori << ' ' << müşteri.adres << '\n';
								cout << endl;

							}
						}
						dosyaoku1.close();
						dosyaz1.close();
						remove("cari.txt");       //cari.txt yi kaldiriyoruz
						rename("cari.tmp", "cari.txt");   //tmp dosyasini txt dosyasina donusturuyoruz

						cout << "Başka firma düzeltmek ister misiniz e/h";
						cin >> durum1;
					} while (durum1 == 'e');

				}
				if (secim2 == 4)    //musteri silmek icin
				{
					char durum;
					do
					{
						int sil;
						cout << "Lütfen silmek istediğiniz firma kodunu giriniz " << endl;  //silinmek istenen firma kodunun kullanicidan istiyoruz
						cin >> sil;
						ifstream dosyaoku1("cari.txt");
						ofstream dosyaz1("cari.tmp");
						while (dosyaoku1 >> müşteri.firmano >> müşteri.firmaad >> müşteri.firmatel >> müşteri.firma_sor >> müşteri.katagori >> müşteri.adres)
						{


							if (sil == müşteri.firmano)  //eslesen firmayi ekrana yazdirip herhangi bir dosya islemi yapmiyoruz
							{
								cout << "silmek istediğiniz firma:" << endl;
								cout << "Firma no       :" << müşteri.firmano << endl;
								cout << "Firma ad       :" << müşteri.firmaad << endl;
								cout << "Firma tel      :" << müşteri.firmatel << endl;
								cout << "Firma sorumlusu:" << müşteri.firma_sor << endl;
								cout << "Firma katagori :" << müşteri.katagori << endl;
								cout << "Firma adresi   :" << müşteri.adres << endl;
							}
							else   //diger musterileri direkt olarak tmp dosyasina yazdiriyoruz
							{

								dosyaz1 << müşteri.firmano << ' ' << müşteri.firmaad << ' ' << müşteri.firmatel << ' ' << müşteri.firma_sor << ' ' << müşteri.katagori << ' ' << müşteri.adres << '\n';
								cout << endl;

							}

						}
						dosyaoku1.close();
						dosyaz1.close();
						remove("cari.txt");
						rename("cari.tmp", "cari.txt");
						cout << "Başka firma silmek ister misiniz e/h";
						cin >> durum;

					} while (durum == 'e');
				}

			} while (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 4);
		}

		if (secim == 3)   //siparis islemleri icin
		{
			int secim3;
			do {
				cout << "Lütfen yapmak istediğiniz işlemi seçiniz " << endl;   //kullanicidan yapmak istedigi islemi aliyoruz
				cout << "Siparis oluştur(1) " << endl;
				cout << "Siparis arama(2) " << endl;
				cout << "Siperis silme(3) " << endl;
				cout << "Siparis Duzeltme (4)" << endl;
				cout << "Siparis Raporlama (5)" << endl;
				cin >> secim3;
				if (secim3 == 1)
				{
					char karar1;
					char karar;

					do
					{
						cout << "Lütfen sipariş oluşturmak istediğiniz firma kodunu giriniz ";  //hangi firma icin siparis olusturulacagini giriyoruz
						cin >> Firmano;

						ifstream Dosyaoku1("cari.txt");  //musteri dosyasindan okuma islemi icin

						while (Dosyaoku1 >> müşteri.firmano >> müşteri.firmaad >> müşteri.firmatel >> müşteri.firma_sor >> müşteri.katagori >> müşteri.adres)
						{


							if (Firmano == müşteri.firmano)  //girilen firma no ile eslesen firmayi buluyoruz
							{
								ofstream Dosyayaz("Sipariş.txt", ios::app);  //siparis.txt yi olusturuyoruz
								do
								{

									cout << "Lütfen sipariş oluşturmak istediğiniz ürün kodunu girinz ";   //girilen firmaya olusturulacak urunun kodunu aliyoruz
									cin >> Urunkod;
									ifstream Dosyaoku("urunler.txt");


									cout << "Lütfen kaç adet siparis geldigini yazınız: ";   //siparis adedini aliyoruz
									cin >> Sipaded;

									ofstream Dosyayaz1("Sipliste.txt", ios::app);   //firmalarin siparislerinin listesini tutacak olan dosya 1 firma birden fazla urun siparis edebilir.
									while (Dosyaoku >> urun.urunkodu >> urun.urun_adi >> urun.urun_uretici >> urun.temin_sure >> urun.tarih >> urun.fiyat >> urun.fiyat_ozel >> urun.kdv >> urun.stokaded)
									{
										Dosyaoku1 >> müşteri.firmano >> müşteri.firmaad >> müşteri.firmatel >> müşteri.firma_sor >> müşteri.katagori >> müşteri.adres;   //musteri bilgilerini okuyoruz

										if (Urunkod == urun.urunkodu)
										{

											if (müşteri.katagori == "ozel")  //eger musteri ozel katagoride ise siparis tutari ozel fiyata gore hesaplaniyor
											{
												siptut += (urun.fiyat_ozel * Sipaded);
											}
											else    //eger degil ise normal fiyatlandirmaya tabii oluyor
											{
												siptut += (urun.fiyat * Sipaded);
											}
										}
									}
									Dosyayaz1 << Firmano << ' ' << Urunkod << ' ' << Sipaded << '\n';        //sipliste.txt dosyasina yaziliyor
									cout << "Bu firma için başka bir ürün sipariş oluşturulacak mı? e/h ";  //bu firma icin baska siparis olustuurlup olusturulmayacagi soruluyor
									cin >> karar;

								} while (karar == 'e');

								cout << "Sipariş tarihi:"; getline(cin >> ws, siptar); // burada siparisle ilgili genel bilgiler aliniyor
								cout << "Siparişi alan:"; getline(cin >> ws, sipalan);
								Dosyayaz << Firmano << ' ' << siptar << ' ' << siptut << ' ' << sipalan << '\n';  //siparisler dosyasina yaziliyor
							}
						}
						cout << "Sipariş oluşturuldu... Başka müşteriler için sipariş oluşturmak ister misiniz ? e/h ";
						cin >> karar1;
					} while (karar1 == 'e');
				}
				if (secim3 == 2)  //siparis arama islemi
				{
					int firma;
					cout << "Lütfen siparişini aramak istediğiniz firma numarasını giriniz: ";  //siparisini aramak istedigimiz firma numarasini aliyoruz
					cin >> firma;
					ifstream Dosyaoku("Sipariş.txt");  //siparis.txtden bilgi okumak icin
					while (Dosyaoku >> Firmano >> siptar >> siptut >> sipalan)
					{


						if (firma == Firmano)  //girdigimiz firmayla eslesen siparisler var ise buluyoruz
						{
							cout << "Firma numarası : " << Firmano << endl;
							cout << "Sipariş Tarihi : " << siptar << endl;
							cout << "Sipariş Tutarı : " << siptut << endl;
							cout << "Siparişi Alan :" << sipalan << endl;
							cout << endl;
						}
						else     //yok ise bulunamadi yaziyoruz
							cout << "Sipariş bulunamadı" << endl;
					}
				}
				if (secim3 == 3)     //siparis silme
				{
					int girdi;
					cout << "Lütfen siparişini silmek istediğiniz firma numarasını giriniz: ";  //fira no yu aliyoruz
					cin >> girdi;
					ifstream Dosyaoku("Sipariş.txt");
					ofstream Dosyayaz("Sipariş.tmp");
					ifstream Dosyaoku1("Sipliste.txt");
					ofstream Dosyayaz1("Sipliste.tmp");
					while (Dosyaoku >> Firmano >> siptar >> siptut >> sipalan)    //dosyadan okuma islemlerini yapiyoruz
					{

						if (girdi == Firmano)        //firma numarasiyla girdi eslesirse ekrana silinmek istenen firmayi yazdiriyoruz ve siliyoruz
						{
							cout << "Silmek istediginiz siparis:" << endl;
							cout << "Firma no      :" << Firmano << endl;
							cout << "Siparis tarihi:" << siptar << endl;
							cout << "Siparis tutari:" << siptut << endl;
							cout << "Siparisi alan :" << sipalan << endl;
						}
						else
						{
							Dosyayaz << ' ' << Firmano << ' ' << siptar << ' ' << siptut << ' ' << sipalan << '\n';  //diger bilgileri Sipliste.tmp dosyasina yazdiriyoruz
						}
					}
					Dosyayaz.close();
					Dosyaoku.close();
					remove("Sipariş.txt");
					rename("Sipariş.tmp", "Sipariş.txt");
					while (Dosyaoku1 >> Firmano >> Urunkod >> Sipaded)       //sonrasinda siparis listesinden urunleri siliyoruz
					{

						if (girdi == Firmano)
						{
						}
						else
						{
							Dosyayaz1 << Firmano << ' ' << Urunkod << ' ' << Sipaded << '\n';
						}
					}
					cout << "Sipariş başarıyla silindi..." << endl;
					Dosyayaz1.close();
					Dosyaoku1.close();
					remove("Sipliste.txt");
					rename("Sipliste.tmp", "Sipliste.txt");
				}


				if (secim3 == 4)
				{
					char karar;
					int firno;
					cout << "Siparisini duzeltmek istediginiz firma no yu giriniz:";   //Siparis duzeltme islemleri icin
					cin >> firno;

					ifstream Dosyaoku("Sipariş.txt");
					ofstream Dosyayaz("Sipariş.tmp", ios::app);
					ifstream Dosyaoku1("Sipliste.txt");
					ofstream Dosyayaz1("Sipliste.tmp", ios::app);
					ifstream Dosyaoku2("Sipliste.txt");
					ifstream Dosyaoku10("cari.txt");
					while (Dosyaoku2 >> Firmano >> Urunkod >> Sipaded)     //Sipliste dosyasindan bilgileri okuyoruz
					{

						if (firno == Firmano)              //eger girilen no ile firmanini eslesirse firmanin hangi urunleri siparis ettigini ekrana yazdiriyoruz
						{
							cout << Firmano << " kodlu firma tarafindan siparis edilen urunler" << endl;
							cout << "Siparis edilen urun kodu : " << Urunkod << endl;
							cout << Urunkod << " Kodlu urunun siparis adedi: " << Sipaded << endl;
							cout << endl;
						}
					}

					while (Dosyaoku1 >> Firmano >> Urunkod >> Sipaded)      //Siplisteden tekrardan bilgileri okuyoruz
					{
						
							if (firno == Firmano)           //eslesen firmayi buluyoruz
							{
								Dosyaoku10 >> müşteri.firmano >> müşteri.firmaad >> müşteri.firmatel >> müşteri.firma_sor >> müşteri.katagori >> müşteri.adres;  //musteri dosyasini okuyoruz




								if (Firmano == müşteri.firmano)  //girilen firma no ile eslesen firmayi buluyoruz
								{
									do {
										cout << "Lütfen sipariş oluşturmak istediğiniz ürün kodunu girinz ";   //siparisini duzeltecegimiz firma icin yeni urunler siparis olusturuyoruz
										cin >> Urunkod;
										ifstream Dosyaoku5("urunler.txt");

										cout << "Lütfen kaç adet siparis geldigini yazınız: ";   //siparis adedini aliyoruz
										cin >> Sipaded;

										while (Dosyaoku5 >> urun.urunkodu >> urun.urun_adi >> urun.urun_uretici >> urun.temin_sure >> urun.tarih >> urun.fiyat >> urun.fiyat_ozel >> urun.kdv >> urun.stokaded)
										{


											if (Urunkod == urun.urunkodu)
											{

												if (müşteri.katagori == "ozel")  //eger musteri ozel katagoride ise siparis tutari ozel fiyata gore hesaplaniyor
												{
													siptut += (urun.fiyat_ozel * Sipaded);
												}
												else    //eger degil ise normal fiyatlandirmaya tabii oluyor
												{
													siptut += (urun.fiyat * Sipaded);
												}
											}
										}
										Dosyayaz1 << Firmano << ' ' << Urunkod << ' ' << Sipaded << '\n';        //sipliste.tmp dosyasina yaziliyor
										cout << "Bu firma için başka bir ürün sipariş oluşturulacak mı? e/h ";  //bu firma icin baska siparis olustuurlup olusturulmayacagi soruluyor
										cin >> karar;

									} while (karar == 'e');

									
								}



							}

							else
							{
								
								Dosyayaz1 << Firmano << ' ' << Urunkod << ' ' << Sipaded << '\n';   //diger firmalarin bilgilerini direkt olarak sipliste.tmpye yaziyoruz
							}
							

					}
					remove("Sipliste.txt");
					rename("Sipliste.tmp", "Sipliste.txt");

					while (Dosyaoku >> Firmano >> siptar >> siptut >> sipalan)        //bu kisimda siparis.txt de bilgilerin duzenlenmesi yapilmistir
					{

						if (firno == Firmano)
						{
							cout << "Sipariş tarihi:"; getline(cin >> ws, siptar); // Burada duzeltilen siparisin yeni tarihini giriyoruz
							cout << "Siparişi alan:"; getline(cin >> ws, sipalan); //duzeltilen siparisi alan kisi
							Dosyayaz << Firmano << ' ' << siptar << ' ' << siptut << ' ' << sipalan << '\n';  //siparisler.tmp dosyasina yaziliyor


						}
						else
						{

							Dosyayaz << Firmano << ' ' << siptar << ' ' << siptut << ' ' << sipalan << '\n';  //siparisler.tmp dosyasina yaziliyor
						}



					}
					remove("Sipariş.txt");
					rename("Sipariş.tmp", "Sipariş.txt");

					cout << "Düzeltme tamamlandı" << endl;
				}




				if (secim3== 5)
				{
					int girdii;                                                                   //Kodunu girdigimiz firmanin siparisini detaylı olarak ekrana yazdiriyoruz
					cout << "Siparisini raporlamak istediginiz Firma kodunu giriniz";
					cin >> girdii;

					ifstream Dosyaoku("Sipariş.txt");
					ifstream Dosyaoku1("Sipliste.txt");
					while (Dosyaoku >> Firmano >> siptar >> siptut >> sipalan)
					{
						if (girdii == Firmano)
						{
							cout << "Siparisi veren Firmanin numarasi  : " << Firmano << endl;
							cout << "Siparisin verildigi tarih         : " << siptar << endl;
							cout << "Siparis tutari                    : " << siptut << endl;
							cout << "Siparisi alan                     :" << sipalan << endl;
							while (Dosyaoku1 >> Firmano >> Urunkod >> Sipaded)
							{
								if (girdii == Firmano)
								{
									cout << "Firmanin siparis verdigi urunler ve adedleri:" << endl;
									cout << "Urun kodu      :" << Urunkod << endl;
									cout << "Siparis adedi  :" << Sipaded << endl;

								}

							}

						}


					}



				}


			} while (secim3 != 1 && secim3 != 2 && secim3 != 3 && secim3 != 4 && secim3 != 5);
		}

		if (secim == 4)
		{

			return EXIT_SUCCESS;



		}


		cout << "Başka bir işlem yapmak ister misiniz? e/h ";
		cin >> durum;

		if (durum == 'e')
			system("cls");  //eger tekrardan islem yapilmak istenirse ekrani siliyoruz

	} while (durum == 'e');

	system("PAUSE");
	return EXIT_SUCCESS;
}