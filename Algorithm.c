//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int *p,x,*sonuc,s=0; //Global de�i�kenleri tan�mlad�m.
void Mutlak(int satir,int sutun);
void KapsananSatir(int satir,int sutun);
void KapsayanSutun(int satir,int sutun);
void Rota(int satir,int sutun);
int Yazdir(int satir,int sutun);

int main(int argc, char* argv[])
{
int satir,sutun;
int i,j,sayac=0;
//Sat�r ve s�tun say�s�n� istedim.
printf("Satir sayisini giriniz: ");
scanf("%d",&satir);
printf("Sutun sayisini giriniz:");
scanf("%d",&sutun);
printf("\n");
x= satir*sutun; //Olu�turaca��m pointer dizisinin alan�n� hesaplad�m.

p=(int *)malloc(sizeof(int)*x);
sonuc=(int *)malloc(sizeof(int)*satir); //Bu pointer dizisine sonu�ta ��kacak sat�rlar� at�yorum.

//Pointer dizisinin elemanlar�n� istiyorum.
for(i=0;i<satir;i++){
for(j=0;j<sutun;j++){
printf("%d.Satir %d.Sutunu giriniz: ",i,j);
scanf("%d",&p[sayac]);
sayac++;
}
}

Yazdir(satir,sutun);

Mutlak(satir,sutun);

printf("Sonuc Satirlari--->");
for(i=0;i<s;i++){
printf(" %d ",sonuc[i]);
}
getchar();getchar();
        return 0;
}
//------------------------------------------

//----------------------------------------
void Mutlak(int satir,int sutun){
int i,j,k,indis,geri,ileri,islem,kolon;
int sayac=0,satir1,sina=0;
for(i=0;i<sutun;i++){
for(j=0;j<satir;j++){
if(p[i+(sutun*j)]==1){ //i de�i�keninin bulundu�u s�tundaki 1'leri kontrol ettirdim.
sayac++;
indis=j; //Hangi sat�rda 1 oldu�unu g�steren j de�i�kenini tuttum.
}
}
if(sayac==1){ //E�er bir s�tunda bir tane bir varsa mutlak sat�r olur.
sina=1; //Mutlak sat�r i�in i�lem yap�ld�ktan sonra mutlak sat�r olu�up olu�mayaca��na bakmak i�in kontrol de�i�keni.
kolon=i+(sutun*indis); //1 de�i�keninin bulundu�u k�sm�n ger�ek pointer yerini tuttum.
satir1=kolon/sutun;

//1 de�i�keninin bulundu�u sat�r�n ilerisini, gerisini, bu sat�rdaki 1'lerin kapsad��� s�tunlar� sildim.
islem=kolon%sutun;
for(j=0;j<=islem;j++){
if(p[kolon-j]==1){
for(k=1;k<satir-satir1;k++){
p[(kolon-j)+(sutun*k)]=0;
}
for(k=1;k<=satir1;k++){
p[(kolon-j)-(sutun*k)]=0;
}
}
p[kolon-j]=0;
}
for(j=0;j<sutun-islem;j++){
if(p[kolon+j]==1){
for(k=1;k<=satir-satir1;k++){
p[(kolon+j)+(sutun*k)]=0;
}
for(k=1;k<=satir1;k++){
p[(kolon+j)-(sutun*k)]=0;
}
}
p[kolon+j]=0;
}
printf("%d.Satir mutlak satirdir.",satir1);
sonuc[s]=satir1;
s++;
printf("\n");
}
sayac=0;
}
if(sina==1){
Yazdir(satir,sutun);
Mutlak(satir,sutun);
}
for(i=0;i<x;i++){
if(p[i]==1){
KapsananSatir(satir,sutun);
}
}
}

//--------------------------------------------------
void KapsananSatir(int satir,int sutun){

int i,j,k,yer,sayac=0,sayac1=0,sina=0;
for(i=0;i<satir;i++){ //Her sat�r i�in her sat�r� ba�tan sona kontrol ettiren d�ng�.
for(j=0;j<satir;j++){
sayac=0;
sayac1=0;
if(i!=j){
for(k=0;k<sutun;k++){
if(p[(i*sutun)+k]==1){   //�lk sat�r�n 1 oldu�u durumda ikinci sat�r da 1'se sayac kontrol de�i�keni artar.
sayac++;                 //�lk sat�r�n 1 oldu�u k�s�mlar i�in ayr�, kapsama ihtimali olan sat�r i�in ayr� saya� var.
if(p[(j*sutun)+k]==1)
sayac1++;
else
break; //De�ilse zaten kapsanan satir olma ihtimali yoktur.
}
}
}
if(sayac!=0 && sayac==sayac1){ //�lk sat�r ve ikinci sat�r�n ayn� yerlerdeki 1 say�lar� kar��la�t�r�l�r.

//Kapsanan sat�rlar� sildim.
for(k=0;k<sutun;k++){
p[(i*sutun)+k]=0;
}
printf("%d.Satir kapsanmistir.",i);
sina++;
printf("\n");
}
}
}
if(sina!=0){
Yazdir(satir,sutun);
Mutlak(satir,sutun);
}
for(i=0;i<x;i++){
if(p[i]==1){
KapsayanSutun(satir,sutun);
}
}
}
//-----------------------------------------------------
void KapsayanSutun(int satir,int sutun){
int i,j,k,sayac=0,sayac1=0,sina=0;
for(i=0;i<sutun;i++){ //Her s�tun i�in her s�tunu ba�tan sonra kontrol eden d�ng�.
for(j=0;j<sutun;j++){
sayac=0;
sayac1=0;
if(i!=j){
for(k=0;k<satir;k++){
if(p[i+(k*sutun)]==1){  //�lk s�tunun 1 oldu�u durumda ikinci sat�r da 1'se sayac kontrol de�i�keni artar.
sayac++;                //�lk s�tunun 1 oldu�u k�s�mlar i�in ayr�, kapsama ihtimali olan s�tun i�in ayr� saya� var.
if(p[j+(k*sutun)]==1)
sayac1++;
else break;
}
}
}
//Kapsayan s�tunlar� sildim.
if(sayac!=0 && sayac==sayac1){
for(k=0;k<satir;k++){
p[(k*sutun)+j]=0;
}
printf("%d.Sutun baska bir sutunu kapsamistir.",j);
printf("\n");
sina++;
}
}
}
if(sina!=0){
Yazdir(satir,sutun);
Mutlak(satir,sutun);
}
for(i=0;i<x;i++){
if(p[i]==1){
Rota(satir,sutun);
}
}
}
//-------------------------------------------------------
void Rota(int satir,int sutun){
int i,j,k,toplam=0,kucuk,sayac=0,sayac1=0,sina=0;
int *p1,kucuk_satir,a=0;
float *p2,toplam1=0,kucuk1;
p1=(int *)malloc(sizeof(int)*sutun);
p2=(float *)malloc(sizeof(float)*satir);
//Ayr� ayr� s�tun a��rl�klar�n� hesaplad�m.
for(i=0;i<sutun;i++){
for(j=0;j<satir;j++){
toplam+=p[i+(j*sutun)];
}
printf("%d  ",toplam);
p1[i]=toplam;  //S�tun a��rl�klar�n� p1 pointer dizisine att�m.
toplam=0;
}

while(p1[a]==0){
a++;
kucuk=p1[a];
}
//En k���k s�tun a��rl���n� hesaplad�m.
for(i=0;i<sutun;i++){
if(p1[i]<kucuk && p1[i]>0)
kucuk=p1[i];
}
//S�tunun tamam� 0 olmayan ka� sat�r oldu�unu hesaplad�m.(Rota form�l� i�in.)
for(i=0;i<satir;i++){
for(j=0;j<sutun;j++){
toplam+=p[j+(i*sutun)];
}
if(toplam>0)
sayac++;
toplam=0;
}

for(i=0;i<sutun;i++){
sayac1=0;
if(p1[i]==kucuk){ //En k���k a��rl��a sahip s�tun �zerinde i�lem yap�lacak.
for(j=0;j<satir;j++){
toplam1=0;
if(p[i+(j*sutun)]==1){ //E�er bu s�tunda 1 varsa 1'in bulundu�u sat�rda 1 oldu�unun kontrol� ger�ekle�iyor.
sayac1++;
for(k=0;k<=i;k++){ //O sat�rda ba�ka 1 var m� bak�l�r.
if(p[i+(j*sutun)-k]==1){ //Bulunulan kolonda 1 ara�t�rmas� i�in gerisine bak�l�r.
toplam1=(toplam1*p1[i-k]+1)/p1[i-k];  //E�er varsa rota form�l�ne eklenir.
}
}
for(k=1;k<sutun-i;k++){
if(p[i+(j*sutun)+k]==1){ //Bulunulan kolonda 1 ara�t�rmas� i�in ilerisine bak�l�r.
toplam1=(toplam1*p1[i+k]+1)/p1[i+k];
}
}
p2[j]=sayac*toplam1; //Rota hesab� p2 pointer dizisine atan�r.
}
else{ //E�er o s�tunun o eleman� 1 de�ilse sa��na soluna 1 var m� varsa da 1'in oldu�u s�tun k���k olan m� diye bak�l�r.
for(k=0;k<=i;k++){
if(p[i+(j*sutun)-k]==1){
if(p1[i-k]==kucuk){
sayac1++; //E�er �yleyse saya� artar ve o sat�r�n d���k sat�r a��rl�klar�ndan birine sahip oldu�u bilinir.
}
}
}
for(k=1;k<sutun-i;k++){
if(p[i+(j*sutun)+k]==1){
if(p1[i+k]==kucuk){
sayac1++; //E�er �yleyse saya� artar ve o sat�r�n d���k sat�r a��rl�klar�ndan birine sahip oldu�u bilinir.
}
}
}
}
if(sayac1==0)
p2[j]=0; //E�er kontrol sat�rlar� i�in saya� hi� artmam��sa sat�r a��rl��� 0 olarak atan�r.
}
}

}
for(i=0;i<satir;i++){
if(p2[i]!=0){
kucuk1=p2[i];
break;
}
}
//En k���k sat�r a��rl��� hesaplan�r.
for(i=0;i<satir;i++){
if(p2[i]<=kucuk1 && p2[i]>0){
kucuk1=p2[i];
kucuk_satir=i;
}
}
//En k���k sat�r a��rl���na sahip olan sat�rlar� siliyorum.
for(i=0;i<sutun;i++){
p[(sutun*kucuk_satir)+i]=0;
}
printf("\n\nRota algoritmasi uygulandi.\n");
Yazdir(satir,sutun);
if(sina!=0){
Yazdir(satir,sutun);
}
for(i=0;i<x;i++){
if(p[i]==1){
Mutlak(satir,sutun);
}
}
}

//------------------------------------------------------
int Yazdir(int satir,int sutun){
int sayac1=0,i,j;
printf("\n");
for(i=0;i<satir;i++){
for(j=0;j<sutun;j++){
printf("%d  ",p[sayac1]);
sayac1++;
}
printf("\n");
}
printf("\n");
return 0;
}
//---------------------------------------------------------------------------
