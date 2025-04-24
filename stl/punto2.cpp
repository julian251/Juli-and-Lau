#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <regex>

// Convierte a minúsculas sin usar locale (funciona con UTF-8 básico)
std::string aMinuscula(const std::string& palabra) {
    std::string resultado;
    for (unsigned char c : palabra) {
        resultado += std::tolower(c);
    }
    return resultado;
}

// Limpia signos de puntuación y mantiene letras con tildes y ñ
std::string limpiarPalabra(const std::string& palabra) {
    std::string limpia = std::regex_replace(palabra, std::regex(R"([^A-Za-zÁÉÍÓÚáéíóúÑñÜü0-9])"), "");
    return aMinuscula(limpia);
}

int main() {
    std::ifstream archivo("sampleFile.txt");
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::map<std::string, int> frecuenciaPalabras;
    std::string linea;

    // Leer el archivo línea por línea
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string palabra;
        
        // Leer palabra por palabra
        while (ss >> palabra) {
            std::string limpia = limpiarPalabra(palabra);
            if (!limpia.empty()) {
                frecuenciaPalabras[limpia]++;  // Incrementar frecuencia
            }
        }
    }

    archivo.close();

    // Mostrar las palabras y su frecuencia
    for (const auto& par : frecuenciaPalabras) {
        std::cout << par.first << ": " << par.second << std::endl;
    }

    return 0;
}