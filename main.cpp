#include <iostream>
#include <string>
#define MAXIM 999

using namespace std;

int nrProduse = 0, key, i, j;
double stoc[MAXIM], preturi[MAXIM];
string produse[999];

void insertKey()
{
    int key;

    while (true)
    {
        cout << "Introduce o tasta: ";
        cin >> key;

        switch (key)
        {
            case 1:
                cout << "Introduce nume: ";
                cin >> produse[nrProduse];
                cout << "Introduce pret: ";
                cin >> preturi[nrProduse];
                cout << "Introduce stoc: ";
                cin >> stoc[nrProduse];
                cout << "Produs adaugat." << endl << endl;
                nrProduse++;
                break;

            case 2:
                cout << "Lista produse:" << endl;
                if (nrProduse == 0)
                    cout << "Nu exista niciun produs!" << endl;
                else
                {
                    for (int i = 0; i < nrProduse; i++)
                        cout << produse[i] << ", pret " << preturi[i] << " lei, si stoc " << stoc[i] << " unitati" << endl;
                }
                cout << endl;
                break;

            case 3:
            {
                string nume;
                cout << "Introduce numele produsului: ";
                cin >> nume;
                bool gasit = false;

                for (int i = 0; i < nrProduse; i++)
                {
                    if (produse[i] == nume)
                    {
                        cout << "Produsul " << nume << " a fost gasit, cu ID-ul " << i + 1 << endl;
                        gasit = true;
                        break;
                    }
                }
                if (gasit == false) cout << "Produsul " << nume << " nu exista in magazin!" << endl;
                cout << endl;
                break;
            }

            case 4:
            {
                int id, amount;
                cout << "Introduce ID-ul produsului: ";
                cin >> id;
                id--;

                cout << "Cat stoc vrei sa vinzi?" << endl;
                cin >> amount;

                if (stoc[id] - amount > 0)
                {
                    stoc[id] -= amount;
                    cout << "Au fost vandute " << amount << " unitati." << endl;
                }
                else if (stoc[id] - amount == 0)
                {
                    for (int i = id; i < nrProduse - 1; i++)
                    {
                        produse[i] = produse[i + 1];
                        preturi[i] = preturi[i + 1];
                        stoc[i] = stoc[i + 1];
                    }
                    nrProduse--;
                    cout << "Stoc epuizat. Produsul a fost eliminat." << endl;
                }
                else
                {
                    cout << "Nu exista suficiente unitati in stoc!" << endl;
                }
                cout << endl;
                break;
            }

            case 5:
            {
                int id, amount;
                cout << "Introduce ID-ul produsului: ";
                cin >> id;
                id--;

                cout << "Cat stoc vrei sa adaugi?" << endl;
                cin >> amount;
                stoc[id - 1] += amount;
                cout << "Stoc nou: " << stoc[id - 1] << endl << endl;
                break;
            }

            case 6:
            {
                if (nrProduse == 0) {
                    cout << "Nu exista niciun produs!" << endl << endl;
                    break;
                }

                int minim = preturi[0], maxim = preturi[0];

                for (int i = 1; i < nrProduse; i++)
                {
                    if (preturi[i] > maxim) maxim = preturi[i];
                    if (preturi[i] < minim) minim = preturi[i];
                }

                cout << "Pretul maxim este de " << maxim << " lei, iar cel minim de " << minim << " lei" << endl << endl;
                break;
            }

            case 7:
            {
                if (nrProduse < 2) {
                    cout << "Nu exista minim 2 produse pentru sortare!" << endl << endl;
                    break;
                }

                for (int i = 0; i < nrProduse - 1; i++)
                {
                    for (int j = i + 1; j < nrProduse; j++)
                    {
                        if (preturi[i] > preturi[j])
                        {
                            swap(preturi[i], preturi[j]);
                            swap(stoc[i], stoc[j]);
                            swap(produse[i], produse[j]);
                        }
                    }
                }
                cout << "Produsele au fost ordonate crescator dupa pret." << endl << endl;
                break;
            }

            case 8:
                cout << "Iesire din program." << endl;
                return;

            default:
                cout << "Tasta invalida!" << endl;
        }
    }
}


int main()
{
    cout << "Tasta 1 pentru a un nou produs." << endl;
    cout << "Tasta 2 pentru a vedea toate produsele din magazin." << endl;
    cout << "Tasta 3 pentru a cauta un produs dupa nume (caps sentitive!)." << endl;
    cout << "Tasta 4 pentru a vinde un produs (scade stoc)." << endl;
    cout << "Tasta 5 pentru a aproviziona un produs (creste stoc)." << endl;
    cout << "Tasta 6 pentru a vedea cel mai ieftin si cel mai scump pret." << endl;
    cout << "Tasta 7 pentru a sorta produsele dupa pret." << endl;
    cout << "Tasta 8 pentru a iesi." << endl << endl;
    insertKey();
    return 0;
}
