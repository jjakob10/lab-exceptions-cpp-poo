#if !defined(FUNCIONARIO_H)
#define FUNCIONARIO_H

#include <string>

using namespace std;

class Departamento;

class Funcionario
{
    int codigo;
    string nome;
    Departamento *d;
public:
    Funcionario(int codigo, const string &nome, Departamento *d);
    Departamento *getDepartamento() const;
    int getCodigo() const;
    const string &getNome() const;
};

#endif // FUNCIONARIO_H
