#include "empresa.h"
#include <stdexcept>

using namespace std;

Departamento &Empresa::createDepartamento(int codigo, const string &nome)
{
    Departamento d(codigo, nome);
    departamentos.insert({codigo, d});
    return departamentos.at(codigo);
}

bool Empresa::containsDepartamento(int codigo) const
{
    return departamentos.find(codigo) != departamentos.end();
}

Departamento &Empresa::findDepartamento(int codigo)
{
    try
    {
        return departamentos.at(codigo);
    }
    catch (out_of_range)
    {
        throw CodigoInvalidoExeption();
    }
}

const map<int, Departamento> &Empresa::getDepartamentos() const
{
    return this->departamentos;
}
