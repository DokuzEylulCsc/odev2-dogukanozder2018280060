#include <iostream>
#include <locale.h> // Konsolda türkçe karakter kullanmak için    http://mesutpiskin.com/blog/cc-turkce-karakter-kullanmak.html
#include <string>
#include <sstream>
using namespace std;

void intToRoman(); //https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
void romanToInt(); //Bu algoritmayý kendim düþündüm ve çalýþtýðý için bu þekilde býraktým fakat daha iyi örnekleri de var
int islemKontrol(int islem);

int main()	{
	setlocale(LC_ALL, "Turkish");
	
	int islem;
	int kontrolEdilmisIslem;
	cout << "Lütfen Bir Ýþlem Seçiniz" << endl;
	cout << "[1]Ondalýk Sayýyý Roma Rakamýna Çevir" << endl;
	cout << "[2]Roma Rakamýný Ondalýk Sayýya Çevir" << endl;
	cin >> islem;
	kontrolEdilmisIslem = islemKontrol(islem);
	if (kontrolEdilmisIslem == 1){
		intToRoman();
	} else if (kontrolEdilmisIslem == 2) {
		romanToInt();
	} 
	return 0;
}


int islemKontrol(int islem){
	string cevap;
	if (islem != 1 && islem != 2){
		cout << "Yanlýþ Girdiniz" << endl;
		cout << "Tekrar Girmek Ýstermisiniz? Y/N" << endl;
		cin >> cevap;
		if (cevap == "Y" || cevap == "y"){
			return main();
		}
	}
	return islem;
}


void intToRoman(){
	int sayi;
	cout << "Lütfen 1 ile 3999 arasýnda bir tamsayý giriniz: ";
	cin >> sayi;	
	if (sayi<1 || sayi>3999) {
		cout << "Yanlýþ girdiniz!" << endl;
		intToRoman();
	}
	string m[] = {"","M","MM","MMM"};
	string c[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	string x[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	string i[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
	string binler , yuzler , onlar , birler , roman;
	binler = m[sayi / 1000];
	yuzler = c[(sayi % 1000) / 100];
	onlar = x[(sayi % 100) / 10];
	birler = i[sayi % 10];
	roman = binler + yuzler + onlar + birler;
	cout << "Girdiðiniz " << sayi << " sayýsýnýn roma rakamlarýndaki karþýlýðý: " << roman << endl;
}


void romanToInt(){
	string roman;
	int romanInt=0;
	int romanUzunluk;
	cout << "Lütfen I ile MMMCMXCIX arasýnda bir roma rakamý giriniz: " << endl;
	cin >> roman;
	romanUzunluk = roman.length();
	
	for (int i = 0; i < romanUzunluk; i++) {
	       
		if (roman[i] == 'M'){
			romanInt=romanInt+1000;
		} else if (roman[i]=='C' && roman[i+1]=='M'){
			i++;
			romanInt=romanInt+900;
		} else if (roman[i]=='D'){
			romanInt=romanInt+500;
		} else if (roman[i]=='C' && roman[i+1]=='D'){
			i++;
			romanInt=romanInt+400;
		} else if (roman[i]=='C'){
			romanInt=romanInt+100;
		} else if (roman[i]=='X' && roman[i+1]=='C'){
			i++;
			romanInt=romanInt+90;
		} else if (roman[i]=='L'){
			romanInt=romanInt+50;
		} else if (roman[i]=='X' && roman[i+1]=='L'){
			i++;
			romanInt=romanInt+40;
		} else if (roman[i]=='X'){
			romanInt=romanInt+10;
		} else if (roman[i]=='I' && roman[i+1]=='X'){
			i++;
			romanInt=romanInt+9;
		} else if (roman[i]=='V'){
			romanInt=romanInt+5;
		} else if (roman[i]=='I' && roman[i+1]=='V'){
			i++;
			romanInt=romanInt+4; 
		} else if (roman[i]=='I'){
			romanInt=romanInt+1;
		}	    
	}
	
	if (romanInt > 3999 || romanInt < 1){
		cout << "Yanlýþ Girdiniz" << endl;
		romanToInt();
	} else	
		cout << "Girdiðiniz " << roman << " sayýsýnýn onluk tabanda karþýlýðý: ";
		cout << romanInt << endl;
}
