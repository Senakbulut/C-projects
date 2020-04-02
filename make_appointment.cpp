#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class akademisyen

{
    public:

        void ogretmenekle();

        void ogretmenyazdir();

    protected:

        string ad,soyad,telno;

        string eposta,bolum,unvan;

        int sicilno;

    private:

};

class ogrenci

{
    public:

        void ogrenciekle();

        void ogrenciyazdir();

    protected:

        string ad,soyad,telno;

        string bolum,eposta;

        int ID,yil;

    private:

};
class randevu : public ogrenci,akademisyen
{

    public:

        void randevuyazdir();

        void randevual();

        int ogrencikontrol(string Id,string tempId);

        int akademisyenkontrol(string sicilNO,string tempsicilno);

        int tarihkonrol(string temptarih);

    protected:

        int ID,sicilno;

        string tarih,baslangicsaat,bitissaat;

    private:

};
void akademisyen::ogretmenekle(){

ofstream dosya;

dosya.open("akademisyen.txt",ios::app);

cout<< "sicilno:"<<" ";

cin>>sicilno;

cout<< "ad:"<<" ";

cin>>ad;

cout<< "soyad:"<<" ";

cin>>soyad;

cout<< "bolum:"<<" ";

cin>>bolum;

cout<< "e posta:"<<" ";

cin>>eposta;

cout<< "telefon numarasi:"<<" ";

cin>>telno;

cout<< "unvan:"<<endl;

cin>>unvan;



dosya<<endl<<sicilno<<" "<<ad<<" "<<soyad<<" "<<bolum<<" "<<eposta<<" "<<telno<<" "<<unvan;



dosya.close();



}

void akademisyen::ogretmenyazdir(){

    ifstream dosya;

    dosya.open("akademisyen.txt");

    while(dosya.eof()==0){

    dosya>>sicilno>>ad>>soyad>>bolum>>eposta>>telno>>unvan;

    cout<<sicilno<<" "<<ad<<" "<<soyad<<" "<<bolum<<" "<<eposta<<" "<<telno<<" "<<unvan<<endl;

    }
    dosya.close();
}

void ogrenci::ogrenciekle(){
    ofstream dosya;

    dosya.open("ogrenci.txt",ios::app);

    cout<< "ID:"<<" ";

    cin>>ID;

    cout<< "ad:"<<" ";

    cin>>ad;

    cout<< "soyad:"<<" ";

    cin>>soyad;

    cout<< "bolum:"<<" ";

    cin>>bolum;

    cout<< "baslangic yili:"<<" ";

    cin>>yil;

    cout<< "e posta:"<<" ";

    cin>>eposta;

    cout<< "telefon numarasi:"<<" ";

    cin>>telno;

    dosya<<endl<<ID<<" "<<ad<<" "<<soyad<<" "<<bolum<<" "<<yil<<" "<<eposta<<" "<<telno;

    dosya.close();
    }

void ogrenci::ogrenciyazdir(){

    ifstream dosya;

    dosya.open("ogrenci.txt");

    while(dosya.eof()==0){

    dosya>>ID>>ad>>soyad>>bolum>>yil>>eposta>>telno;

    cout<<ID<<" "<<ad<<" "<<soyad<<" "<<bolum<<" "<<yil<<" "<<eposta<<" "<<telno<<endl;

    }

    dosya.close();

    }

void randevu::randevuyazdir(){



   ifstream dosya;

   dosya.open("randevu.txt");

   while(dosya.eof()==0){

   dosya>>ID>>sicilno>>tarih>>baslangicsaat>>bitissaat;

   cout<<ID<<" "<<sicilno<<" "<<tarih<<" "<<baslangicsaat<<" "<<bitissaat<<endl;

   }

}

void randevu::randevual(){

    ofstream dosya1;

    string temptarih;

    string Id;

    string tempId;

    string sicilNO;

    string tempsicilno;

    ifstream dosya;

    string tempbaslangic;

    string tempbitis;

    bool saatuygun=1;



   dosya.open("ogrenci.txt");

   cout<<"ID"<<" ";

   cin>>tempId;

if(ogrencikontrol(Id,tempId)!=1){

    cout<<"boyle bir ogrenci bulunmamaktadir."<<endl;

    return ;

}

cout<<"sicilno"<<" ";

cin>>tempsicilno;

if(akademisyenkontrol(sicilNO,tempsicilno)!=1){

    cout<< "boyle bir akademisyen bulunmamaktadir."<<endl;

    return ;



}

cout<< "tarih"<< " ";

cin>>temptarih;

if(tarihkonrol(temptarih)==0){



dosya1.open("randevu.txt",ios::app);

cout<< "baslangic saati giriniz:"<<endl;

cin>>baslangicsaat;

cout<< "bitis saati giriniz:"<<endl;

cin>>bitissaat;

cout<< "eklendi"<<endl;

dosya1<<endl<<tempId<<" "<<tempsicilno<<" "<<temptarih<<" "<<baslangicsaat<<" "<<bitissaat;

dosya1.close();

return ;

}

dosya.close();

dosya.open("randevu.txt");

cout<< "baslangic saati giriniz:"<<endl;

cin>>tempbaslangic;

cout<< "bitis saati giriniz:"<<endl;

cin>>tempbitis;

int bassaat=0,saatend=0;

int bitsaat=0,saatstart=0;

int basdk=0,dkstart=0;

int bitdk=0,dkend=0;

while(dosya.eof()==0){

dosya>>Id>>sicilNO>>tarih>>baslangicsaat>>bitissaat;

if((Id.compare(tempId)==0||tempsicilno.compare(sicilNO)==0)&&tarih.compare(temptarih)==0){

    bassaat = (baslangicsaat[0]-'0')*10+(baslangicsaat[1]-'0');

    bitsaat = (bitissaat[0]-'0')*10+(bitissaat[1]-'0');

    saatstart=(tempbaslangic[0]-'0')*10+(tempbaslangic[1]-'0');

    saatend=(tempbitis[0]-'0')*10+(tempbitis[1]-'0');



    basdk = (baslangicsaat[3]-'0')*10+(baslangicsaat[4]-'0');

    bitdk = (bitissaat[3]-'0')*10+(bitissaat[4]-'0');

    dkstart = (tempbaslangic[3]-'0')*10+(tempbaslangic[4]-'0');

    dkend = (tempbitis[3]-'0')*10+(tempbitis[4]-'0');

   if((saatend<bassaat||(saatend==bassaat&&dkend<=basdk))||(saatstart>bitsaat||(saatstart==bitsaat&&dkend>=bitdk))){
   }

   else {

    saatuygun=0;

    break;

   }

    }

}

dosya.close();

if(saatuygun==0){

   cout<< "saat doludur"<<endl;

   saatuygun=1;

    return;

}

else{

    cout<<"eklendi";

    dosya1.open("randevu.txt",ios::app);

    dosya1<<endl<<tempId<<" "<<tempsicilno<<" "<<temptarih<<" "<<tempbaslangic<<" "<<tempbitis;

    dosya1.close();

}
}

int randevu::ogrencikontrol(string Id,string tempId){

ifstream dosya;
dosya.open("ogrenci.txt");

while(dosya.eof()==0){

dosya>>Id;

if(Id.compare(tempId)==0){

    cout<<"ogrenci bulundu"<<endl;

    return 1;

}

}

dosya.close();

return 0;

}

int randevu::akademisyenkontrol(string sicilNO,string tempsicilno){

   ifstream dosya;

   dosya.open("akademisyen.txt");

   while(dosya.eof()==0){

    dosya>>sicilNO;

if(sicilNO.compare(tempsicilno)==0){

    cout<< "akademisyen bulundu"<<endl;

    return 1;

}

   }

dosya.close();

return 0;
}

int randevu::tarihkonrol(string temptarih){

ifstream dosya;

dosya.open("randevu.txt");

while(dosya.eof()==0){

    dosya>>tarih;
    if(temptarih.compare(tarih)==0){

           dosya.close();

        return 1;
    }
}
dosya.close();

return 0;

}
int main(){

    akademisyen akaddemi1;
    ogrenci ogrenci1;
    randevu randevu1;

    int x;

while(x!=7){

    cout<< "ogrenci eklemek icin: 1"<<endl;

    cout<< "ogrenciyi yazdirmak icin: 2"<<endl;

    cout<< "akademisyen eklemek icin: 3"<<endl;

    cout<< "akademisyeni yazdirmak icin: 4"<<endl;

    cout<< "randevu almak icin: 5"<<endl;

    cout<< "randevu listesini gormek icin: 6"<<endl;

    cout<< "cikmak icin :7"<<endl;

    cin>>x;
    switch(x){

    case 1:

        ogrenci1.ogrenciekle();

        break;

    case 2:

        ogrenci1.ogrenciyazdir();

        break;

    case 3:

        akaddemi1.ogretmenekle();

        break;

    case 4:

        akaddemi1.ogretmenyazdir();

        break;

    case 5:

        randevu1.randevual();

        break;

    case 6:

        randevu1.randevuyazdir();

        break;

    case 7:

       break;
}

}
    return 0;

}
