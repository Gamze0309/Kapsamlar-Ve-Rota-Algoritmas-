//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int *p,x,*sonuc,s=0; //Global deðiþkenleri tanýmladým.
void Mutlak(int satir,int sutun);
void KapsananSatir(int satir,int sutun);
void KapsayanSutun(int satir,int sutun);
void Rota(int satir,int sutun);
int Yazdir(int satir,int sutun);

int main(int argc, char* argv[])
{
int satir,sutun;
int i,j,sayac=0;
//Satýr ve sütun sayýsýný istedim.
printf("Satir sayisini giriniz: ");
scanf("%d",&satir);
printf("Sutun sayisini giriniz:");
scanf("%d",&sutun);
printf("\n");
x= satir*sutun; //Oluþturacaðým pointer dizisinin alanýný hesapladým.

p=(int *)malloc(sizeof(int)*x);
sonuc=(int *)malloc(sizeof(int)*satir); //Bu pointer dizisine sonuçta çýkacak satýrlarý atýyorum.

//Pointer dizisinin elemanlarýný istiyorum.
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
if(p[i+(sutun*j)]==1){ //i deðiþkeninin bulunduðu sütundaki 1'leri kontrol ettirdim.
sayac++;
indis=j; //Hangi satýrda 1 olduðunu gösteren j deðiþkenini tuttum.
}
}
if(sayac==1){ //Eðer bir sütunda bir tane bir varsa mutlak satýr olur.
sina=1; //Mutlak satýr için iþlem yapýldýktan sonra mutlak satýr oluþup oluþmayacaðýna bakmak için kontrol deðiþkeni.
kolon=i+(sutun*indis); //1 deðiþkeninin bulunduðu kýsmýn gerçek pointer yerini tuttum.
satir1=kolon/sutun;

//1 deðiþkeninin bulunduðu satýrýn ilerisini, gerisini, bu satýrdaki 1'lerin kapsadýðý sütunlarý sildim.
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
for(i=0;i<satir;i++){ //Her satýr için her satýrý baþtan sona kontrol ettiren döngü.
for(j=0;j<satir;j++){
sayac=0;
sayac1=0;
if(i!=j){
for(k=0;k<sutun;k++){
if(p[(i*sutun)+k]==1){   //Ýlk satýrýn 1 olduðu durumda ikinci satýr da 1'se sayac kontrol deðiþkeni artar.
sayac++;                 //Ýlk satýrýn 1 olduðu kýsýmlar için ayrý, kapsama ihtimali olan satýr için ayrý sayaç var.
if(p[(j*sutun)+k]==1)
sayac1++;
else
break; //Deðilse zaten kapsanan satir olma ihtimali yoktur.
}
}
}
if(sayac!=0 && sayac==sayac1){ //Ýlk satýr ve ikinci satýrýn ayný yerlerdeki 1 sayýlarý karþýlaþtýrýlýr.

//Kapsanan satýrlarý sildim.
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
for(i=0;i<sutun;i++){ //Her sütun için her sütunu baþtan sonra kontrol eden döngü.
for(j=0;j<sutun;j++){
sayac=0;
sayac1=0;
if(i!=j){
for(k=0;k<satir;k++){
if(p[i+(k*sutun)]==1){  //Ýlk sütunun 1 olduðu durumda ikinci satýr da 1'se sayac kontrol deðiþkeni artar.
sayac++;                //Ýlk sütunun 1 olduðu kýsýmlar için ayrý, kapsama ihtimali olan sütun için ayrý sayaç var.
if(p[j+(k*sutun)]==1)
sayac1++;
else break;
}
}
}
//Kapsayan sütunlarý sildim.
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
//Ayrý ayrý sütun aðýrlýklarýný hesapladým.
for(i=0;i<sutun;i++){
for(j=0;j<satir;j++){
toplam+=p[i+(j*sutun)];
}
printf("%d  ",toplam);
p1[i]=toplam;  //Sütun aðýrlýklarýný p1 pointer dizisine attým.
toplam=0;
}

while(p1[a]==0){
a++;
kucuk=p1[a];
}
//En küçük sütun aðýrlýðýný hesapladým.
for(i=0;i<sutun;i++){
if(p1[i]<kucuk && p1[i]>0)
kucuk=p1[i];
}
//Sütunun tamamý 0 olmayan kaç satýr olduðunu hesapladým.(Rota formülü için.)
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
if(p1[i]==kucuk){ //En küçük aðýrlýða sahip sütun üzerinde iþlem yapýlacak.
for(j=0;j<satir;j++){
toplam1=0;
if(p[i+(j*sutun)]==1){ //Eðer bu sütunda 1 varsa 1'in bulunduðu satýrda 1 olduðunun kontrolü gerçekleþiyor.
sayac1++;
for(k=0;k<=i;k++){ //O satýrda baþka 1 var mý bakýlýr.
if(p[i+(j*sutun)-k]==1){ //Bulunulan kolonda 1 araþtýrmasý için gerisine bakýlýr.
toplam1=(toplam1*p1[i-k]+1)/p1[i-k];  //Eðer varsa rota formülüne eklenir.
}
}
for(k=1;k<sutun-i;k++){
if(p[i+(j*sutun)+k]==1){ //Bulunulan kolonda 1 araþtýrmasý için ilerisine bakýlýr.
toplam1=(toplam1*p1[i+k]+1)/p1[i+k];
}
}
p2[j]=sayac*toplam1; //Rota hesabý p2 pointer dizisine atanýr.
}
else{ //Eðer o sütunun o elemaný 1 deðilse saðýna soluna 1 var mý varsa da 1'in olduðu sütun küçük olan mý diye bakýlýr.
for(k=0;k<=i;k++){
if(p[i+(j*sutun)-k]==1){
if(p1[i-k]==kucuk){
sayac1++; //Eðer öyleyse sayaç artar ve o satýrýn düþük satýr aðýrlýklarýndan birine sahip olduðu bilinir.
}
}
}
for(k=1;k<sutun-i;k++){
if(p[i+(j*sutun)+k]==1){
if(p1[i+k]==kucuk){
sayac1++; //Eðer öyleyse sayaç artar ve o satýrýn düþük satýr aðýrlýklarýndan birine sahip olduðu bilinir.
}
}
}
}
if(sayac1==0)
p2[j]=0; //Eðer kontrol satýrlarý için sayaç hiç artmamýþsa satýr aðýrlýðý 0 olarak atanýr.
}
}

}
for(i=0;i<satir;i++){
if(p2[i]!=0){
kucuk1=p2[i];
break;
}
}
//En küçük satýr aðýrlýðý hesaplanýr.
for(i=0;i<satir;i++){
if(p2[i]<=kucuk1 && p2[i]>0){
kucuk1=p2[i];
kucuk_satir=i;
}
}
//En küçük satýr aðýrlýðýna sahip olan satýrlarý siliyorum.
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
