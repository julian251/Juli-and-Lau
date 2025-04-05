 # Versión mínima requerida de CMake
cmake_minimum_required(VERSION 3.22)

# Nombre del proyecto
project(Cuenta_bancaria)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir el directorio de encabezados
include_directories(include)

# Agregar la biblioteca con los archivos fuente
add_library(Cuentas_lib src/CuentaBancaria.cpp)

# Agregar el ejecutable con el archivo principal
add_executable(Cuentas main/punto_4.cpp)

# Vincular la biblioteca al ejecutable
target_link_libraries(Cuentas Cuentas_lib)