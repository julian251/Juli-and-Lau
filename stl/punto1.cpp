#include <iostream>     // Para entrada/salida estándar
#include <fstream>      // Para manejar archivos
#include <set>          // Para almacenar palabras únicas
#include <sstream>      // Para separar palabras de líneas
#include <string>       // Para manejar strings
#include <regex>        // Para limpiar palabras con expresiones regulares
#include <locale>       // Para manejar acentos y conversión con tildes

// Función que limpia una palabra:
// - Elimina signos de puntuación
// - Conserva letras con tildes y la ñ
// - Convierte todo a minúsculas usando configuración regional en español
std::string limpiarPalabra(const std::string& palabra) {
    // Elimina todos los caracteres que NO sean letras (incluyendo acentos), números o ñ
    std::string limpia = std::regex_replace(palabra, std::regex(R"([^A-Za-zÁÉÍÓÚáéíóúÑñÜü0-9])"), "");

    // Establece una configuración regional en español para manejar correctamente las tildes
    std::locale loc("es_ES.UTF-8"); // Asegúrate de que tu sistema tenga este locale

    // Convierte la palabra limpia a minúsculas
    std::string resultado;
    for (char c : limpia) {
        resultado += std::tolower(c, loc);
    }

    return resultado;
}

int main() {
    std::set<std::string> palabras;         // Set para guardar palabras únicas
    std::ifstream archivo("sampleFile.txt");   // Abre el archivo de texto a leer

    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::string linea;
    // Lee el archivo línea por línea
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea); // Permite dividir la línea en palabras
        std::string palabra;

        // Extrae palabras de la línea una por una
        while (ss >> palabra) {
            std::string limpia = limpiarPalabra(palabra); // Limpia la palabra

            if (!limpia.empty()) {
                palabras.insert(limpia); // Guarda la palabra limpia en el set (sin duplicados)
            }
        }
    }

    archivo.close(); // Cierra el archivo

    // Muestra las palabras únicas en la consola
    for (const auto& palabra : palabras) {
        std::cout << palabra << std::endl;
    }

    return 0;
}