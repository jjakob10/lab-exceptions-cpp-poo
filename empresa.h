#if !defined(EMPRESA_H)
#define EMPRESA_H

#include <map>
#include <string>

#include "departamento.h"

using namespace std;

class Empresa
{
    map<int, Departamento> departamentos;

public:
    Departamento &createDepartamento(int codigo, const string &nome);
    Departamento &findDepartamento(int codigo);
    bool containsDepartamento(int codigo) const;
    const map<int, Departamento> &getDepartamentos() const;
    class CodigoInvalidoExeption
    {
    };
};

#endif // EMPRESA_H
