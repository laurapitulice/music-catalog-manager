/*
                                10.MUZICA
0)structura melodie - tip de date special pentru a stoca titlul, interpretul, durata
1)preluarea a n cantece de la tastatura si stocarea lor
2)afisarea cantecelor stocate
3)sa se scrie toate datele sticate intr un fisier
4)sa se afiseze toate cantecele interpretate de un anume solist(solist de la tastatura)
5)ordonare dupa titlu
6)durata totala
*/

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//0)
struct melodie{
    char titlu[100];
    char artist[100];
    struct timp
    {
        unsigned int minute;
        unsigned int secunde;
    }timp;

};

//variabile globale
melodie lista[100];
int n,i,j;
unsigned int auxx;
char a[100];
char aux[100];

//1)
void citire(int i=i){

    cout<<"titlul(fara spatii):";
        cin>>lista[i].titlu;
    cout<<"interpret(fara spatii):";
        cin>>lista[i].artist;
    cout<<"minute: ";
        cin>>lista[i].timp.minute;
    cout<<"secunde: ";
        cin>>lista[i].timp.secunde;

}
void citire2(){
    for(i=0 ; i<n ; i++) citire();
    cout<<endl;
}

//2)
void afisare(int i=i){
    cout<<"MELODIE "<<i+1<<":"<<endl;
        cout<<lista[i].titlu<<" de ";
        cout<<lista[i].artist<<endl;
        cout<<lista[i].timp.minute<<":"<<lista[i].timp.secunde;
        cout<<endl;

}
void afisare2(){
    for(i=0 ; i<n ; i++) afisare();
    cout<<endl;
}

//3)
void fisier(){
ofstream m("iesire.out");
    for(i=0;i<n;i++){
        m<<"MELODIE "<<i+1<<" :"<<endl;
        m<<lista[i].titlu<<" ";
        m<<lista[i].artist<<endl;
        m<<lista[i].timp.minute<<":"<<lista[i].timp.secunde;
        m<<endl;}
}

//4)
void lafel(){
    cin>>a;
    for(i=0;i<n;i++){
            if(strcmp(lista[i].artist,a)==0){
                afisare(i);
                }
    }
}

//5)
void ordonare(){

        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                    if(strcmp(lista[i].titlu,lista[j].titlu)>0){

                        strcpy(aux,lista[i].titlu);
                        strcpy(lista[i].titlu,lista[j].titlu);
                        strcpy(lista[j].titlu,aux);

                        strcpy(aux,lista[i].artist);
                        strcpy(lista[i].artist,lista[j].artist);
                        strcpy(lista[j].artist,aux);

                        auxx=lista[i].timp.minute;
                        lista[i].timp.minute=lista[j].timp.minute;
                        lista[j].timp.minute=auxx;

                        auxx=lista[i].timp.secunde;
                        lista[i].timp.secunde=lista[j].timp.secunde;
                        lista[j].timp.secunde=auxx;
}
}

//6)
void durata(){
    int s_min=0;
    int s_sec=0;
    int s_ore=0;
    for(i=0;i<n;i++){
        s_min+=lista[i].timp.minute;
        s_sec+=lista[i].timp.secunde;}
    while(s_sec>=60){
        s_min++;
        s_sec-=60;
    }
    while(s_min>=60){
        s_ore++;
        s_min-=60;
    }
    cout<<"durata totala de ascultare este: "<<endl;
    cout<<s_ore<<":"<<s_min<<":"<<s_sec;
}

//
int main()
{
    cout<<"numarul melodiilor: ";
    cin>>n;
    int o;
    do{
        cout<<"Dati optiunea: "<<endl<<"1-citire"<<endl<<"2-afisare"<<endl<<"3-ordonare"<<endl<<"4-fisier"<<endl<<"5-durata totala"<<endl<<"6-melodii de un anumit artist"<<endl<<"0-pt iesire"<<endl;
        cin>>o;
        switch(o){
            case 1: citire2(); break;
            case 2: afisare2(); break;
            case 3: ordonare(); break;
            case 4: fisier(); break;
            case 5: durata(); break;
            case 6: lafel(); break;
            default: if(o!=0) cout<<"Valoarea citita este gresita.";break;

        }
        cout<<endl;
    }while(o!=0);

    return 0;
}