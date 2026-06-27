#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Equipo rojo - Integrantes: Franco Sanchez Angel Alexis

void dibujarAhorcado(int intentosRestantes) {
    cout << " ___     \n";
    cout << " |       |     \n";
    cout << " |       " << (intentosRestantes > 0 ? "O" : " ") << "\n";
    cout << " |      " << (intentosRestantes > 2 ? "/" : " ")
                       << (intentosRestantes > 1 ? "|" : " ")
                       << (intentosRestantes > 3 ? "\\" : " ") << "\n";
    cout << " |      " << (intentosRestantes > 4 ? "/" : " ")
                       << " "
                       << (intentosRestantes > 5 ? "\\" : " ") << "\n";
    cout << " |\n |\n|____\n\n";
}

int main() {
    cout << R"(

  ___   _   _  _____ ______  _____   ___  ______  _____ 
 / _ \ | | | ||  _  || ___ \/  __ \ / _ \ |  _  \|  _  |
/ /_\ \| |_| || | | || |_/ /| /  \// /_\ \| | | || | | |
|  _  ||  _  || | | ||    / | |    |  _  || | | || | | |
| | | || | | |\ \_/ /| |\ \ | \__/\| | | || |/ / \ \_/ /
\_| |_/\_| |_/ \___/ \_| \_| \____/\_| |_/|___/   \___/ 

)" << endl;
    cout << "=================== by red team ========================\n";

    // Leer palabras del archivo
    ifstream archivo("palabras.txt");
    vector<string> palabras;
    string palabra;
    while (archivo >> palabra)
        palabras.push_back(palabra);
    archivo.close();

    // Elegir palabra aleatoria
    srand(static_cast<unsigned int>(time(nullptr)));
    string palabraSecreta = palabras[rand() % palabras.size()];
    string palabraMostrada(palabraSecreta.length(), '_');

    int intentos = 6;

    while (intentos > 0) {
        cout << "\nPalabra: " << palabraMostrada;
        cout << "\nIntentos restantes: " << intentos;
        cout << "\nIngresa una letra: ";

        char letra;
        cin >> letra;

        bool letraEncontrada = false;
        for (size_t i = 0; i < palabraSecreta.length(); ++i) {
            if (palabraSecreta[i] == letra) {
                palabraMostrada[i] = letra;
                letraEncontrada = true;
            }
        }

        if (!letraEncontrada) {
            --intentos;
            cout << "Letra incorrecta. ¡Inténtalo de nuevo!\n";
        }

        dibujarAhorcado(6 - intentos);

        if (palabraMostrada == palabraSecreta) {
            cout << "\n¡Victoria magistral! Has adivinado la palabra: " << palabraSecreta << "\n";
            break;
        }
    }

    if (intentos == 0) {
        cout << "\n¡Apestas...! La palabra era: " << palabraSecreta << "\n";
        dibujarAhorcado(6);
    }

    return 0;
}