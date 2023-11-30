#if !defined(DEPARTAMENTO_H)
#define DEPARTAMENTO_H

#include <string>
#include <map>

#include "funcionario.h"

using namespace std;

class Departamento
{
    int codigo;
    string nome;
    map<int,Funcionario> funcionarios;
public:
    Departamento(const int &codigo, const string &nome);    
    Funcionario &createFuncionario(const int &codigo, const string &nome);
    const map<int,Funcionario> &getFuncionarios() const;
    const string &getNome() const;
    const int &getCodigo() const;
};

#endif // DEPARTAMENTO_H
