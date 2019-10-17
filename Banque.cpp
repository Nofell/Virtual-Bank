#include <iostream>
#include <cmath>
#include <string>
 
using namespace std;

#include "Banque.hpp"

Client::Client()
{
    Numero_CIN = "FR7593658305736503750375937";
    Nom = "TEST";
    Prenom = "test";
    Numero_Tel = 0600000000;
    int code = 0000;
    principal = new Compte;

}

Client::Client(string Numero_CINbis, string Nombis, string Prenombis, long Numero_Telbis, int Codebis)
{
    Numero_CIN = Numero_CINbis;
    Nom = Nombis;
    Prenom = Prenombis;
    Numero_Tel = Numero_Telbis;
    Code = Codebis;
}

string Client::getCIN()
{
    return Numero_CIN;
}

string Client::getNom()
{
    return Nom;
}

string Client::getPrenom()
{
    return Prenom;
}

long Client::getTel()
{
    return Numero_Tel;
}

int Client::getCode()
{
    return Code;
}


void Client::setCIN(string nCIN)
{
    Numero_CIN = nCIN;
}
void Client::setNom(string nNom)
{
    Nom = nNom;
}

void Client::setPrenom(string nPrenom)
{
    Prenom = nPrenom;
}

void Client::setTel(long nNumero_Tel)
{
    Numero_Tel = nNumero_Tel;
}

void Client::setCode(int nCode)
{
    Code = nCode;
}





















Compte::Compte()
{
    Numero_Compte = 0000000000;
    Solde = 1000;
}

Compte::Compte(int Numero_Comptebis, int Soldebis)
{
    Numero_Compte = Numero_Comptebis;
    Solde = Soldebis;
}

int Compte::getSolde()
{
    return Solde;
}

void Compte::setSolde(int nSolde)
{
    Solde = nSolde;
}

void Compte::CrediterDeposer(int montantDepo)
{
    float a;
    cout << "Combien voulez vous deposer : ";
    cin >> a;
    montantDepo = montantDepo + a;
    cout << "Votre solde est de : "<< montantDepo << endl;
}

void Compte::CrediterPrendre(int montantDepo, int Numero_Compte)
{

} 
        
void Compte::Debiter()
{
    float a;
    cout << "Combien voulez vous retirer : ";
    cin >> a;
    Solde = Solde - a;
    cout << "Votre solde est de : "<< Solde << endl;
} 

void Compte::Virement()
{

} 

void Compte::Commander()
{

} 

void Compte::AfficherInfo(Client toto)
{
    cout << toto.getCIN() << endl;
    cout << toto.getNom() << endl;
    cout << toto.getPrenom() << endl;
    cout << toto.getTel() << endl;
    cout << toto.getCode() << endl;

} 

