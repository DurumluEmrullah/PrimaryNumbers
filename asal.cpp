#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

int main(){
	int dizi[2];
	dizi[0]=2;
	int flag =0;
	int z=0;
	int n =1;
	string dosyaAd;
	char dosyaAdi[20];
	cout<<"Baslangic degerini giriniz : "<<endl;
	int b,f;
	cin>>b;
	if(b<3) b=3;
	cout<<"Son degeri giriniz : "<<endl;
	cin>>f;
	if(f<0) f*=-1;	
	cout<<"Olusturulcak dosya adini giriniz :(Ornek dosyaAdi.xls) "<<endl;
	cin>>dosyaAd;
	for(int i=0;i<sizeof(dosyaAd);i++){
	dosyaAdi[i]=dosyaAd[i];
	}
	
	ofstream dosyayaz(dosyaAdi);
	dosyayaz<<"Sayi \t(n)/f(fn-1)\tf(n-1)/f(n)\tn/ f(n)\tf(n)/n"<<endl;

	for(int i =b;i<f;i+=2){

		flag=0;
		
		for(int j=3;j<=ceil(sqrt(i));j+=2){
			if(i%j==0){
				flag=1;	
				break;
				}
			
		}
		if(flag==0){
			n++;
			z++;
			dizi[z%2]=i;

			dosyayaz<<i<<"\t"<<(double)dizi[z%2]/dizi[(z-1)%2]<<"\t"<<(double)dizi[(z-1)%2]/dizi[z%2]<<"\t"<<(double)n/i<<"\t"<<(double)i/n<<endl;

	}
	}
	dosyayaz.close();

	}	
