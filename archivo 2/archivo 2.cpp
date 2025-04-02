#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ArchivoTexto {
private:
    static const string rutaArchivo;
public:
    static void crearArchivoSiNoExiste() {
        ofstream archivo(rutaArchivo, ios::app);
        if (!archivo) {
            cout << "Error al crear el archivo.\n";
        }
        else {
            archivo.close();
        }
    }

    static void escribirEnArchivo(const string& texto) {
        ofstream archivo(rutaArchivo, ios::app);
        if (archivo.is_open()) {
            archivo << texto << endl;
            archivo.close();
            cout << "Texto guardado exitosamente.\n";
        }
        else {
            cout << "Error al abrir el archivo.\n";
        }
    }

    static void leerArchivo() {
        ifstream archivo(rutaArchivo);
        string linea;
        if (archivo.is_open()) {
            cout << "\nContenido del archivo:\n";
            while (getline(archivo, linea)) {
                cout << linea << endl;
            }
            archivo.close();
        }
        else {
            cout << "Error al abrir el archivo o el archivo no existe.\n";
        }
    }

    static void sobrescribirArchivo(const string& nuevoContenido) {
        ofstream archivo(rutaArchivo);
        if (archivo.is_open()) {
            archivo << nuevoContenido;
            archivo.close();
            cout << "Archivo actualizado exitosamente.\n";
        }
        else {
            cout << "Error al abrir el archivo.\n";
        }
    }

    static void eliminarArchivo() {
        if (remove(rutaArchivo.c_str()) == 0) {
            cout << "Archivo eliminado exitosamente.\n";
        }
        else {
            cout << "Error al eliminar el archivo.\n";
        }
    }
};

const string ArchivoTexto::rutaArchivo = "\\\\192.168.146.197\\archivos\\grupo_video_juegos.txt";

int main() {
    ArchivoTexto::crearArchivoSiNoExiste();

    int opcion;
    do {
        cout << "\n--- Menu de Archivo ---\n";
        cout << "1. Escribir en el archivo\n";
        cout << "2. Leer el archivo\n";
        cout << "3. Sobrescribir el archivo\n";
        cout << "4. Eliminar el archivo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string texto;
            cout << "Ingrese el texto a guardar: ";
            getline(cin, texto);
            ArchivoTexto::escribirEnArchivo(texto);
        }
        else if (opcion == 2) {
            ArchivoTexto::leerArchivo();
        }
        else if (opcion == 3) {
            string nuevoContenido;
            cout << "Ingrese el nuevo contenido del archivo: ";
            getline(cin, nuevoContenido);
            ArchivoTexto::sobrescribirArchivo(nuevoContenido);
        }
        else if (opcion == 4) {
            ArchivoTexto::eliminarArchivo();
        }
        else if (opcion == 5) {
            cout << "Saliendo...\n";
        }
        else {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}

