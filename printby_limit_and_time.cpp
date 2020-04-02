#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct belg{
  string dosyayol;
  string dosyaboyut;
  int sayfasay;

struct kisibilg{
  string ad;
  string soyad;
  string kullaniciad;
  string eposta;
  int dogumyil;
  }kisi;

  struct tarihler{
  int yil;
  int gun;
  int ay;
  int saat;
  int dak;
  int sn;
  }tarih;
};

int main(int argc, char* argv[])
{
  int i=0;
  int j=0;
  int limit;
  int sure;
  int clock = 1;
  int yazmasure;
  cout << "limit: ";
  cin >> limit;
  cout << "sure: ";
  cin >> sure;
  cout << "yazmasure: ";
  cin >> yazmasure;
  belg veri[limit];

  ifstream belge;
  belge.open(argv[1]);

  int kontrol[limit];

  for(int k = 0 ; k < limit ; k++){
    kontrol[k] = 0;

  }
  while(1){

cout << clock << "saniye"<<endl;
if(belge.eof()==1 && kontrol[1]==0&&kontrol[limit-1]==0){

return 0;
}
if(kontrol[i] == 0 && clock%sure == 0){

belge >> veri[i].dosyayol >>
veri[i].dosyaboyut >>
veri[i].sayfasay >>
veri[i].kisi.ad >>
veri[i].kisi.soyad >>
veri[i].kisi.kullaniciad >>
veri[i].kisi.eposta >>
veri[i].kisi.dogumyil >>
veri[i].tarih.yil >>
veri[i].tarih.gun >>
veri[i].tarih.ay >>
veri[i].tarih.saat >>
veri[i].tarih.dak >>
veri[i].tarih.sn;

cout <<
veri[i].dosyayol <<" eklendi"<<endl;
kontrol[i] = 1;
i++;
}
if(kontrol[j]== 1 && (clock - sure) % yazmasure == 0 && clock > sure ){

veri[j].sayfasay--;

if(veri[j].sayfasay == 0 ){

cout <<
veri[j].dosyayol <<
veri[j].sayfasay <<" yazdirildi"<<endl;
kontrol[j] = 0;
j++;

}
}

clock++;
    if(i == limit)
        i=0;
    if(j == limit)
        j=0;
  }
belge.close();

    return 0;
}
