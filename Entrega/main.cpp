#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

#include "header.h"

using std::cout;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::list;
using std::sort;
using std::getline;

int main (int argc, char **argv)
{
    if (argc < 3)
    {
        cout << "Modo de uso:\n";
        cout << "./main <archivo de entrada> <archivo de salida>";
        cout << "(y, opcionalmente) <archivo de personalizacion>\n";
        return 0;
    }
    const bool esPers = (argc == 4);
    ifstream inputParameter;
    inputParameter.open(argv[1]);
    const bool metodo = [&inputParameter](bool x){return inputParameter >> x, x;}({});
    const double c = [&inputParameter](double x){return inputParameter >> x, x;}({});
    const bool tipoDeRanking = [&inputParameter](bool x){return inputParameter >> x, x;}({});

    string strTemp;
    inputParameter >> strTemp;
    ifstream inputFile;
    inputFile.open(strTemp);

    const double epsilon = [&inputParameter](double x){return inputParameter >> x, x;}({});

    ofstream outputFile;
    outputFile.open(argv[2]);
    if (!tipoDeRanking)
    {
        //caso ranking de paginas web
        //cout << "------------- RANKING WEB ---------------\n";
        int size;
        
        //tiro a la basura las primeras 4 lineas (excepto la cantidad de nodos)
        for (int i = 0; i < 4;)
        {
            if (i == 2)
            {
                inputFile >> strTemp;
                inputFile >> strTemp;
                inputFile >> size;
                inputFile.ignore(1024, '\n');
                i++;
            }
            else
            {
                inputFile.ignore(1024, '\n');
                i++;
            }
        }
        list<tupla<int, int>> listaTuplas;
        int prim; int seg;
        while (inputFile >> prim)
        {
            inputFile >> seg;
            listaTuplas.push_back(tupla<int, int>(prim, seg));
        }
        
        if (!metodo)
        {
            //caso Pagerank
            //cout << "METODO: Page Rank\n";

            vector<int> hist;
            double p;
            if (esPers)
            {
                ifstream persFile;
                persFile.open(argv[3]);
                persFile >> p;
                int prim;
                hist = vector<int>(size);
                while (persFile >> prim)
                {
                    int seg;
                    persFile >> seg;
                    hist[prim - 1] = seg;
                }
                persFile.close();
            }

            CCS P;
            if (esPers) P = CCS(listaTuplas, hist, size, p);
            else P = CCS(listaTuplas, size);
            CCSTranspuesta P_Transpuesta(P, size);
            inputParameter.close();
            inputFile.close(); 
            
            vector<double> v(size, 1.0/size);
            unique_ptr<vector<double>> res = powerMethod(P_Transpuesta, size, c, epsilon, v);
            //vector<tupla<double, int>> pageRank(size);
            //for (int i = 0; i < size; i++) pageRank[i] = tupla<double, int>((*res)[i], i + 1);
            //sort(pageRank.begin(), pageRank.end(), 
            //        [](tupla<double, int> a, tupla<double, int> b) {return b < a;});
            //cout << "RESULTADO: \n";
            //for (int i = 0; i < size; i++) cout << pageRank[i].segundo << '\n';
            //cout << '\n';
            for (int i = 0; i < size; i++) outputFile << (*res)[i] << '\n';
            outputFile.close();
            return 0;
        }
        else {
            inputParameter.close();
            cout << "METODO: Indeg\n";
            //----------INDEG---------------
            vector<tupla<int,int>> nodos(size, tupla<int,int>(0,0));
            for (int i = 0; i < size; i++) {
                nodos[i].primero = i+1;
            }
            indeg(listaTuplas, nodos);
            //----------
            //ordenar nodos (salida del indeg)
            int aux_prim = 0;
            int aux_seg = 0;
            for (int i = 1; i < size; i++) {
                int j = i;
                while(j > 0 && nodos[j].segundo > nodos[j-1].segundo) {
                    aux_prim = nodos[j].primero;
                    aux_seg = nodos[j].segundo;
                    nodos[j].primero = nodos[j-1].primero;
                    nodos[j].segundo = nodos[j-1].segundo;
                    nodos[j-1].primero = aux_prim;
                    nodos[j-1].segundo = aux_seg;
                    j--;
                }
            }
            //----------
            cout << "RESULTADO: \n";
            for (int i = 0; i < nodos.size(); i++) {
                outputFile << nodos[i].primero << "\n";
                cout << nodos[i].primero << "\n";
            }
            cout << '\n';
            outputFile.close();
            return 0;
        }
    }
    else {

        //----------GEM---------------
        cout << "----------- RANKING DEPORTIVO -----------\n";

        int tipo_rank;
        int fecha_hasta;
        string urlEquipos;
        
        if (inputParameter >> tipo_rank) {
            //-------------------------------------------------------
            ////-------------------- EXPERIMENTOS -------------------
            inputParameter >> fecha_hasta;
            inputParameter >> urlEquipos;
            ifstream inputEquipos;
            inputEquipos.open(urlEquipos);
            
            inputParameter.close();

            int size;
            inputFile >> size;
            inputFile >> strTemp;

            //leo los equipos
            vector<string> equipos('a');
            for (int i = 0; i < size; ++i) {
                getline(inputEquipos, strTemp, ',');
                getline(inputEquipos, equipos[i]);
            }

            if (tipo_rank == 1) {
                //-------------- ESTANDAR ----------------
                cout << "METODO: Estándar\n";
                int fecha_datos;
                bool fin_datos = false;
                tupla<int, int> eq1;
                tupla<int, int> eq2;

                //EQUIPO:
                //      -> id
                //      -> datos
                //              -> puntos
                //              -> goles
                //                      -> a favor
                //                      -> en contra

                vector<tupla<int,tupla<int,tupla<int,int>>>> R(size,tupla<int, tupla<int,tupla<int,int>>>(size,tupla<int,tupla<int,int>>(0,tupla<int,int>(0,0))));

                for (int i = 0; i < size; ++i) {
                    R[i].primero = i+1;
                }

                inputFile >> fecha_datos;
                while(fecha_datos <= fecha_hasta && !fin_datos) {
                    inputFile >> eq1.primero;
                    inputFile >> eq1.segundo;
                    inputFile >> eq2.primero;
                    inputFile >> eq2.segundo;
                    //sumo goles a favor
                    R[eq1.primero-1].segundo.segundo.primero += eq1.segundo;
                    R[eq2.primero-1].segundo.segundo.primero += eq2.segundo;
                    //sumo goles en contra
                    R[eq1.primero-1].segundo.segundo.segundo += eq2.segundo;
                    R[eq2.primero-1].segundo.segundo.segundo += eq1.segundo;
                    if (eq1.segundo == eq2.segundo) {
                        //empate
                        R[eq1.primero-1].segundo.primero += 1;
                        R[eq2.primero-1].segundo.primero += 1;
                    } else if (eq1.segundo > eq2.segundo) {
                        //gano el 1
                        R[eq1.primero-1].segundo.primero += 3;
                    } else {
                        //gano el 2
                        R[eq2.primero-1].segundo.primero += 3;
                    }
                    if (! (inputFile >> fecha_datos)) {
                        fin_datos = true;
                    }
                }

                //ordeno por puntos
                int aux_prim = 0;
                tupla<int,tupla<int,int>> aux_data(0, tupla<int,int>(0,0));
                for (int i = 1; i < size; ++i) {
                    int j = i;
                    while (j > 0 && R[j].segundo.primero > R[j-1].segundo.primero ) {
                        aux_prim = R[j].primero;
                        aux_data.primero = R[j].segundo.primero;
                        aux_data.segundo.primero = R[j].segundo.segundo.primero;
                        aux_data.segundo.segundo = R[j].segundo.segundo.segundo;

                        R[j].primero = R[j-1].primero;
                        R[j].segundo.primero = R[j-1].segundo.primero;
                        R[j].segundo.segundo.primero = R[j-1].segundo.segundo.primero;
                        R[j].segundo.segundo.segundo = R[j-1].segundo.segundo.segundo;

                        R[j-1].primero = aux_prim;
                        R[j-1].segundo.primero = aux_data.primero;
                        R[j-1].segundo.segundo.primero = aux_data.segundo.primero;
                        R[j-1].segundo.segundo.segundo = aux_data.segundo.segundo;
                        j--;
                    }
                }

                //imprimo los resultados por pantalla
                cout << "\tEquipo\t\tGaF\tGeC\tPuntos\n";
                cout << "----------------------------------------------------\n";
                for (int i = 0; i < size; ++i) {
                    cout << i+1 << "\t" << equipos[R[i].primero-1] << "\t\t" << R[i].segundo.segundo.primero << "\t" << R[i].segundo.segundo.segundo << "\t" << R[i].segundo.primero << "\n";
                }
                //imprimo los resultados en el archivo de salida
                outputFile << "\\begin{tabulary}{0.6\\textwidth}{| c | c | c | c | c |}\n";
                outputFile << "\\hline\n";
                outputFile << "& \\textbf{Equipo} & \\textbf{Goles a Favor} & \\textbf{Goles en Contra} & \\textbf{Puntos} \\\\ \\hline\n";
                for (int i = 0; i < size; ++i) {
                    outputFile << i+1 << " & " << equipos[R[i].primero-1] << " & " << R[i].segundo.segundo.primero << " & " << R[i].segundo.segundo.segundo << " & " << R[i].segundo.primero << "\\\\ \\hline\n";
                }
                outputFile << "\\end{tabulary}\n";
                //-------------- FIN ESTANDAR ----------------
            } else if(tipo_rank == 2) {
                //--------------- GEM ------------------
                cout << "METODO: GeM\n";
                vector<vector<double>> G(size, vector<double>(size, 0));

                gem(inputFile, c, G);


                vector<double> v(size, 1.0/size);
                double dist;
                vector<tupla<int,double>> resultado(size, tupla<int, double>(0,0.0));
                do {
                    for (int i = 0; i < size; i++) {
                        resultado[i].segundo = 0;
                        for (int j = 0; j < size; j++) {
                            //uso los indices al revez para usar G_TRASPUESTA
                            resultado[i].primero = i+1;
                            resultado[i].segundo += G[j][i] * v[j];
                        }
                    }

                    dist = 0;
                    for (int i = 0; i < size; i++) {
                        dist += fabs(v[i] - resultado[i].segundo);
                        v[i] = resultado[i].segundo;
                    }
                } while (dist > epsilon);

                //ordeno para mostrar
                int aux_prim = 0;
                double aux_seg = 0.0;
                for (int i = 1; i < size; i++) {
                    int j = i;
                    while(j > 0 && resultado[j].segundo > resultado[j-1].segundo) {
                        aux_prim = resultado[j].primero;
                        aux_seg = resultado[j].segundo;
                        resultado[j].primero = resultado[j-1].primero;
                        resultado[j].segundo = resultado[j-1].segundo;
                        resultado[j-1].primero = aux_prim;
                        resultado[j-1].segundo = aux_seg;
                        j--;
                    }
                }

                //imprimo los resultados por pantalla
                cout << "\tEquipo\tNumero\n";
                cout << "-------------------------------\n";
                for (int i = 0; i < size; ++i) {
                    cout << i+1 << "\t" << equipos[resultado[i].primero-1] << "\t" << resultado[i].segundo << "\n";
                }
                //imprimo los resultados en el archivo de salida
                outputFile << "\\begin{tabulary}{0.4\\textwidth}{ | c | c | c |}\n";
                outputFile << "\\hline\n";
                outputFile << "& \\textbf{Equipo} & \\textbf{Numero}\\\\ \\hline\n";
                for (int i = 0; i < size; ++i) {
                    outputFile << i+1 << " & " << equipos[resultado[i].primero-1] << " & " << resultado[i].segundo << "\\\\ \\hline\n";
                }
                outputFile << "\\end{tabulary}\n";
                //--------------- FIN GEM ------------------

            }

            

            outputFile.close();
            return 0;
            //----------------- FIN EXPERIMENTOS --------------------
            //-------------------------------------------------------

        } else {

            inputParameter.close();

            cout << "METODO: GeM\n";
            int size;
            inputFile >> size;
            inputFile >> strTemp;

            vector<vector<double>> G(size, vector<double>(size, 0));

            gem(inputFile, c, G);


            vector<double> v(size, 1.0/size);
            double dist;
            vector<tupla<int,double>> resultado(size, tupla<int, double>(0,0.0));
            do {
                for (int i = 0; i < size; i++) {
                    resultado[i].segundo = 0;
                    for (int j = 0; j < size; j++) {
                        //uso los indices al revez para usar G_TRASPUESTA
                        resultado[i].primero = i+1;
                        resultado[i].segundo += G[j][i] * v[j];
                        //cout << "resultado[" << i << "] += " << G[j][i] << "*" << v[j] << "\n";
                    }
                }

                dist = 0;
                for (int i = 0; i < size; i++) {
                    dist += fabs(v[i] - resultado[i].segundo);
                    v[i] = resultado[i].segundo;
                }
            } while (dist > epsilon);


            for (int i = 0; i < size; i++) {
                outputFile << resultado[i].segundo << "\n";
            }

            //ordeno para mostrar por pantalla
            int aux_prim = 0;
            double aux_seg = 0.0;
            for (int i = 1; i < size; i++) {
                int j = i;
                while(j > 0 && resultado[j].segundo > resultado[j-1].segundo) {
                    aux_prim = resultado[j].primero;
                    aux_seg = resultado[j].segundo;
                    resultado[j].primero = resultado[j-1].primero;
                    resultado[j].segundo = resultado[j-1].segundo;
                    resultado[j-1].primero = aux_prim;
                    resultado[j-1].segundo = aux_seg;
                    j--;
                }
            }
            cout << "RESULTADO: \n";
            for (int i = 0; i < size; ++i) {
                cout << resultado[i].primero << "\t" << resultado[i].segundo << "\n";
            }
            cout << "\n";

            outputFile.close();


            return 0;
            
        }




    }
} 
