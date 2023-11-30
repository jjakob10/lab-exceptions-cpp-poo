#include "departamento.h"

Departamento::Departamento(const int &codigo, const string &nome) 
    : codigo(codigo), nome(nome)
{
}

Funcionario &Departamento::createFuncionario(const int &codigo, const string &nome)
{
    Funcionario f(codigo,nome, this);
    funcionarios.insert({codigo,f});
    return funcionarios.at(codigo);
}

const map<int, Funcionario> &Departamento::getFuncionarios() const
{
    return this->funcionarios;
}

const string &Departamento::getNome() const
{
    return nome;
}

const int &Departamento::getCodigo() const
{
    return codigo;
}
