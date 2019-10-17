#ifndef BANQUE_H
#define BANQUE_H

#include <string>
using namespace std;

class Client
{
    private: 
        string Numero_CIN;
        string Nom;
        string Prenom;
        long Numero_Tel;
        int Code;
    
        Compte *principal;

    public:
        Client();
        Client(string, string, string, long, int); 

        string getCIN();
        string getNom();
        string getPrenom();
        long getTel();
        int getCode();

        void setCIN(string);
        void setNom(string);
        void setPrenom(string);
        void setTel(long);
        void setCode(int);

};











class Compte
{
    private:
        int Numero_Compte;
        int Solde;
         

    public:
        Compte();
        Compte(int Numero_Compte, int Solde);

        int getSolde();
        
        void setSolde(int); 

        void CrediterDeposer(int montantDepo);
        void CrediterPrendre(int montantDepo, int Numero_Compte); 
        void Debiter(); 
        void Virement(); 
        void Commander(); 
        void AfficherInfo(Client);
    
};


#endif
