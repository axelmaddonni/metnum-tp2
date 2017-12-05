#include "header.h"

CCS::CCS() : values(vector<double>()), rowIndex(vector<int>()), colPtr(vector<int>()) {}

CCS::CCS(list<tupla<int, int>>& in, int n) : values(vector<double>()), rowIndex(vector<int>()), colPtr(vector<int>()) 
{
    colPtr.push_back(1);
    for (int i = 1; i < n + 1; i++)
    {
        int count = 0;
        while (true)
        {
            tupla<int, int> actual;
            if ((!in.empty()) && (actual = in.front()).primero == i)
            {
                in.pop_front();
                rowIndex.push_back(actual.segundo);
                count++;
            }
            else 
            {
                colPtr.push_back(colPtr[colPtr.size() - 1] + count);
                for (int j = 0; j < count; j++) values.push_back(1.0/count);
                break;
            }
        }
    } 
}

CCSTranspuesta::CCSTranspuesta(CCS& in, int n) : values(vector<double>()), colIndex(vector<int>()), rowPtr(vector<int>())
{
    list<tupla<int, int>> buckets[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = in.colPtr[i]; j < in.colPtr[i + 1]; j++)
        {
            buckets[in.rowIndex[j - 1] - 1].push_back(tupla<int, int>(j, i + 1));
        }
    }
    rowPtr.push_back(1);
    for (int i = 0; i < n; i++)
    {
        rowPtr.push_back(rowPtr[rowPtr.size() - 1] + buckets[i].size());
        while (!buckets[i].empty())
        {
            tupla<int, int> top = buckets[i].front();
            buckets[i].pop_front();
            values.push_back(in.values[top.primero - 1]);
            colIndex.push_back(top.segundo);
        }
    }
}

void vecCrossMatrix (vector<double>& vec, vector<double>& res, CCSTranspuesta& mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = mat.rowPtr[i] - 1; j < mat.rowPtr[i + 1] - 1; j++)
        {
            sum += vec[mat.colIndex[j] - 1] * mat.values[j];
        }
        res[i] = sum;
    }
}

unique_ptr<vector<double>> powerMethod (CCSTranspuesta& mat, int n, double c, double epsilon, vector<double>& v)
{
    unique_ptr<vector<double>> resPtr(new vector<double>(n));

    vector<double> x = v;
    vector<double>& y(*resPtr);
    double w;
    double sigma;
    do
    {
        double temp = 0;
        double temp2 = 0;
        double temp3 = 0;
        vecCrossMatrix(x, y, mat, n);
        for (int i = 0; i < n; i++) y[i] *= c;
        for (int i = 0; i < n; i++) 
        {
            temp += fabs(x[i]);
            temp2 += fabs(y[i]);
        }
        w = temp - temp2;
        for (int i = 0; i < n; i++) y[i] += w * v[i];
        for (int i = 0; i < n; i++)
        {
            temp3+= fabs(y[i] - x[i]);
        }
        sigma = temp3;
        x = y;
    } while (sigma > epsilon);

    return resPtr;
}

CCS::CCS(list<tupla<int, int>>& in, vector<int>& historial, int& n, const double& p) : values(vector<double>()), rowIndex(vector<int>()), colPtr(vector<int>()) 
{
    colPtr.push_back(1);
    for (int i = 1; i < n + 1; i++)
    {
        int count = 0;
        int total = 0;
        while (true)
        {
            tupla<int, int> actual;
            if ((!in.empty()) && (actual = in.front()).primero == i)
            {
                in.pop_front();
                rowIndex.push_back(actual.segundo);
                count++;
                total += historial[actual.segundo - 1];
            }
            else 
            {
                for (int j = 0; j < count; j++) 
                { 
                    double persChance;
                    double unifChance = (1 - p) * (1.0/count);
                    if (total)
                    {
                        persChance = p * historial[rowIndex[colPtr[colPtr.size() - 1] - 1] + j - 1] / total;
                        values.push_back(unifChance + persChance);
                    }
                    else values.push_back(unifChance);
                }
                colPtr.push_back(colPtr[colPtr.size() - 1] + count);
                break;
            }
        }
    }
}
