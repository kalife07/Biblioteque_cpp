#include<iostream>
using namespace std;

class Livre{
	private:
		char* auteur, *titre, *editeur;
		float prix;
		int stock;
	
    public:
    // constructeur -> Cela est comme un blueprint de l’objet qui specifie ce qu’on doit inclure dans l’objet
        Livre(){
            auteur = new char[20];
            titre = new char[20];
            editeur = new char[20];
        }

        void mettredata(){
            // creer un ui ou l'utilisateur entre 
            // nom d'atuer
            // titre du livre
            // nom du publication
            // prix du livre
            // position du stock( stock qui reste)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string temp_auteur;
            cout << "Nom de lauteur: \n";
            getline(cin, temp_auteur);
            strcpy(auteur, temp_auteur.c_str());
            string temp_titre;
            cout << "Nom du titre: \n";
            getline(cin, temp_titre);
            strcpy(titre, temp_titre.c_str());
            string temp_publication;
            cout << "Nom de la publication: \n";
            getline(cin, temp_publication);
            strcpy(editeur, temp_publication.c_str());
            cout << "Prix: \n";
            cin >> prix;
            cout << "Stock restant: \n";
            cin >> stock;
        }
        void editerdata() {
            int choix_util;
            cout << "Que veux-tu changer?\n1.Titre\n2.Auteur\n3.Prix"<<endl;
            cin >> choix_util;
            if (choix_util==1) {
                string nou_titre;
                cout << "Entrer le nom du nouveau titre: ";
                cin >> nou_titre;
                strcpy(titre, nou_titre.c_str());
            }
            else if (choix_util==2) {
                string nou_auteur;
                cout << "Entrer le nom du nouveau auteur: ";
                cin >> nou_auteur;
                strcpy(auteur, nou_auteur.c_str());
            }
            else if (choix_util==3) {
                float nou_prix;
                cout << "Entrer le nouveau prix: ";
                cin >> nou_prix;
                prix = nou_prix;
            }
        }

        string get_titre() {
            return titre;
        }

        string get_auteur() {
            return auteur;
        }

        string get_editeur() {
            return editeur;
        }

        float get_prix() {
            return prix;
        }

        int get_stock() {
            return stock;
        }

        void montredata(){
            // Visuel du programme C++ du livre
            cout<<"\nNom de l'auteur: "<<auteur;
            cout<<"\nTitre: "<<titre;
            cout<<"\nÉditeur: "<<editeur;
            cout<<"\nPrix: "<<prix;
            cout<<"\nStock disponible: "<<stock<<endl;
            cout<<endl;

        }

        void achetelivre(){
            int nb_copies;
            cout<<"\nEntrer le nombre de copies: ";
            cin>>nb_copies;
            if(nb_copies <= stock)
            {
                    cout<<"Ce nombre de copies est disponible"<<endl;
                    cout<<"\nPrix de "<< nb_copies <<"  livres est : "<<nb_copies*prix<<"$";
                    cout<<"\nMerci .... Revenez encore....";
                    stock = stock-nb_copies;
            }
            else
            {
                    cout<<"\nCe nombre de copies n'est pas disponible"  ;
                    cout<<"\nDésolé pour l'inconvénience...";
                    cout<<"\nMerci .... Revenez encore....";
            }
        }

};

int main() {
    Livre L[20];
    int i=0;
    char titreacheter[20],auteuracheter[20];
    bool rouler_programme = true;
    while (rouler_programme) {
        cout << "***Bienvenue à la biblioteque D'Adel***"<<endl;
        cout << "---------------------------------"<<endl;
        int choix;
        cout << "1.Entrer un livre\n2.Acheter un livre\n3.Chercher un livre\n4.Changer details d'un livre\n5.Lister tous les livres\n6.Quitter l'application\n";
        cin >> choix;
        
        string choix_livre;
        int L_length;
        L_length = i;
        switch (choix) {
            case 1: 
                L[i].mettredata();
                i++;
                break;
            case 2:
            //revoir
            cin.ignore(); 
                cout << "Quel livre voulez vous acheter? "<<endl;
                getline(cin, choix_livre);
                for (int i=0;i<L_length;i++) {
                    if (choix_livre==L[i].get_titre()) {
                        L[i].achetelivre();
                    }
                }
                break;
            case 3:
            cin.ignore(); 
                cout << "Quel livre voulez-vous rechercher? "<<endl;
                getline(cin, choix_livre);
                for (int i=0;i<L_length;i++) {
                    if (choix_livre==L[i].get_titre()) {
                        L[i].montredata();
                    }
                }
                break;
            case 4:
            cin.ignore(); 
                cout << "Quel livre voulez vous editer? ";
                getline(cin, choix_livre);
                for (int i=0;i<L_length;i++) {
                    if (choix_livre==L[i].get_titre()) {
                        L[i].editerdata();
                    }
                }
                break;
            case 5:
                for (int i=0;i<L_length;i++) {
                    cout<<i+1<<"."<<L[i].get_auteur()<<", "<<L[i].get_titre()<<" (stock restant: "<<L[i].get_stock()<<", prix: "<<L[i].get_prix()<<", editeur: "<<L[i].get_editeur()<<")"<<endl;
                    cout<<"\n";
                }
                break;
            case 6:
                cout << "Au revoir";
                rouler_programme = false;
                break;
            default:
                cout << "Choisi 1 a 5";

        }
    }
    return 0;
}
