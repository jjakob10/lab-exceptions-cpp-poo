#include "funcionario.h"

Funcionario::Funcionario(int codigo, const string &nome, Departamento *d) : 
        codigo(codigo), nome(nome), d(d)
{
}

Departamento *Funcionario::getDepartamento() const
{
    return this->d;
}

int Funcionario::getCodigo() const
{
    return this->codigo;
}

const string &Funcionario::getNome() const
{
    return this->nome;
}
