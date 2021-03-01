#include <stdarg.h>

#ifndef VECTORND_H
#define VECTORND_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <math.h>

using namespace std;

class VectorND {
private:

	int n;
	double * A;
	double norma;
	string name;

public:
	VectorND() {};
	VectorND(initializer_list<double> List);
	VectorND(initializer_list<double> List, string N);

    void updateName(string s) {name = s;}

    void initCopyVectorND(const VectorND& v) {

        this->n = v.n;
        this->norma = v.norma;
        this->name = v.name + "'";
        this->A = (double *) malloc (v.n * sizeof(double));

        if (this->A != NULL) {
            for(int i = 0; i < n; i++){
                this->A[i] = v[i];
            }
            updateNorm();
        } else {
            cout << "\n-->No Memory for " << this->name << endl;
        }
    }

    void initCopyVectorNDtype2(const VectorND& v, string newName) {

        this->n = v.n;
        this->norma = v.norma;
        this->name = newName;
        this->A = (double *) malloc (v.n * sizeof(double));

        if (this->A != NULL) {
            for(int i = 0; i < n; i++){
                this->A[i] = v[i];
            }
            updateNorm();
        } else {
            cout << "\n-->No Memory for " << this->name << endl;
        }
    }

    void initVectorNDType2(int n){

        this->n = n;
        this->A = (double *) malloc (n * sizeof(double));
    }

    void SumVectorND(VectorND B, VectorND C)
{
    if(C.dim() != B.dim())
        printf("\n\n SumVectorND :: THIS OPERATION CANNOT BE EXECUTED \n\n CHECK DIMENSION \n\n");
    
    else{
        
        for(int i = 0; i < this->n; i++)
            this->A[i] = B.access(i) + C.access(i);

        double norma = 0;
        for (int i = 0; i < this->n; i++)
            norma += this->A[i] * this->A[i];

        this->norma = sqrt(norma);  

    }
}

    void initVectorND(int n, ...){

        va_list list;
        this->n = n;
        this->A = (double *) malloc (n * sizeof(double));
        int i;
    
        va_start(list, n);
        /**/
        /**/    for (int i = 0; i < n; i++)
        /**/        this->A[i] = va_arg(list, double);
        /**/
        va_end(list);
        
        double norma = 0;
        for (i = 0; i < this->n; i++)
            norma += this->A[i] * this->A[i];
    
        this->norma = sqrt(norma);
    }

    void zeroVectorND(int n) {

    this->initVectorNDType2(n);
    for (int i = 0; i < n; i++)
            this->A[i] = 0;

    this->norma = 0.0;
}

    double access(int i) {return A[i];}

    void updateVector3D(double x, double y, double z) {

        A[0] = x;
        A[1] = y;
        A[2] = z;

    };

    void updateVector3DP(const VectorND& v) {

        A[0] = v[0];
        A[1] = v[1];
        A[2] = v[2];

    };
    
    void initZeroVectorND(int m, string N) {
        this->name = N;
        this->n = m;
        this->A = (double *) malloc (m * sizeof(double));
        if (this->A != NULL) {
            for(int i = 0; i < m; i++){
                this->A[i] = 0.0;
            }
            updateNorm();
        } else {
            cout << "\n-->No Memory for " << name << endl;
        }
    }

	~VectorND() {

		//cout << "\n-->Destroying Vector " << name << "\n";
		//free(A);
		//A = NULL;
	};

	double& operator [] (int);
    double  operator [] (int) const;
    void escVectorND(string s) const;

    int dim() const {return n;}
    double norm() const {return norma;}
    string vectorName() const {return name;}

    void updateNorm() {

    	this->norma = 0.0;
    	for (int i = 0; i < n; i++)
    		norma += A[i]*A[i];

    	this->norma = sqrt(norma);
    }

    void addVectorNDP(const VectorND& b) {
    	
    	if (n != b.n)
    		cout << "\nError in addition, dimensions " << name << " := " << n << "  and  " << b.name << " := " << b.n;
    	else {

    		//this->name += " + " + b.name; 
    		for (int  i = 0; i < b.n; i++) {
    			A[i] += b[i];
    		}
    	}

    	updateNorm();
    }

    void subVectorNDP(const VectorND& b) {
    	
    	if (n != b.n)
    		cout << "\nError in subtraction, dimensions " << name << " := " << n << "  and  " << b.name << " := " << b.n;
    	else {

    		//this->name += " + " + b.name; 
    		for (int  i = 0; i < b.n; i++) {
    			A[i] -= b[i];
    		}
    	}

    	updateNorm();
    }

    void addVectorND(const VectorND& a, const VectorND& b) {

    	if (a.n != b.n)
    		cout << "\nError in addition, dimensions " << a.name << " := " << a.n << "  and  " << b.name << " := " << b.n;
    	else {

    		//this->name = a.name + " - " + b.name; 
    		for (int  i = 0; i < b.n; i++) {
    			this->A[i] = a[i] + b[i];
    		}
    	}

    	updateNorm();
    }

    void subVectorND(const VectorND& a, const VectorND& b) {

    	if (a.n != b.n)
    		cout << "\nError in subtraction, dimensions " << a.name << " := " << a.n << "  and  " << b.name << " := " << b.n;
    	else {

    		//this->name = a.name + " - " + b.name; 
    		for (int  i = 0; i < b.n; i++) {
    			this->A[i] = a[i] - b[i];
    		}
    	}

    	updateNorm();
    }

    void scalarMultND(double x) {

		//string s = to_string(x);
		//s += " * (" + name + ")";
		//this->name = s;
	
		for (int i = 0; i < n; i++)
			A[i] *= x;
	
		updateNorm();
	}

	double dot(const VectorND& a, const VectorND& b) {

		double sum = 0;

		for (int i = 0; i < n; i++)
			sum += a.A[i] * b.A[i];

		return sum;
	}

    void piecewiseMotion(int timeInt, VectorND updateVector, const VectorND& target, const VectorND& source, int numScenes) {

                double time = (double) timeInt;
                double numS = (double) numScenes;
                double t = time/numS;

                //cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"  << t << endl;

                updateVector.updateVector3D(
                    (t * (target[0] - source[0])) + source[0] + 0.0000001,
                    (t * (target[1] - source[1])) + source[1] + 0.0000001,
                    (t * (target[2] - source[2])) + source[2] + 0.0000001
                );
    }

	double metrica(const VectorND& a, const VectorND& b) {

		double m = dot(a, b);
		return sqrt(m);
	}

	void unit() {

		string s = name;
		this->scalarMultND(1.0/norma);
		name = "unit(" + s + ")";
	}

    void Cross3D(VectorND B, VectorND C){
    
        this->n = 3;
    
        if(C.dim() != B.dim())
            printf("\n\n THIS OPERATION CANNOT BE EXECUTED \n\n CHECK DIMENSION \n\n"); 
        else{
            this->A[0] = ( B[1] * C[2]) - (B[2] * C[1]);
            this->A[1] = (-B[0] * C[2]) + (B[2] * C[0]);
            this->A[2] = ( B[0] * C[1]) - (B[1] * C[0]);    
            
            double norma = 0;   
            for (int i = 0; i < this->n; i++)
                norma += this->A[i] * this->A[i];
        
            this->norma = sqrt(norma);
        }
                    
    }

    void dilate(const VectorND& head, const VectorND& source, double lambda) {

        subVectorND(head, source);
        scalarMultND(lambda);
        addVectorNDP(source);
    }
	
};

VectorND :: VectorND(initializer_list<double> List){

				this->name = "NO_NAME";
            	double suma = 0.0;
            	this->n = List.size();
            	this->A = (double*) malloc (List.size()*sizeof(double));
            	
            	if (this->A != NULL) {
            		for(int index=0; index<List.size(); ++index){
                		this->A[index] = List.begin()[index];
            		}
            		updateNorm();
            	} else {
            		cout << "\n-->No Memory\n";
            	}
        	};

VectorND :: VectorND(initializer_list<double> List, string N){

				this->name = N;
            	double suma = 0.0;
            	this->n = List.size();
            	this->A = (double*) malloc (List.size()*sizeof(double));
            	
            	if (this->A != NULL) {
            		for(int index=0; index<List.size(); ++index){
                		this->A[index] = List.begin()[index];
            		}
            		updateNorm();
            	} else {
            		cout << "\n-->No Memory\n";
            	}
        	};

void VectorND :: escVectorND(string s) const {

	if (s == "info") {
		cout << "\nName := " << name;
		cout << "\nDimension := "<< n <<", VectorND(";

		for (int i = 0; i < n; i++) {
			cout << " " << A[i]; 
		}

		cout << "), and norm := " << this->norma << "\n";

	}

	if (s == "matrix") {

        cout << "(";
		for (int i = 0; i < n; i++) {
            cout << " " << A[i]; 
        }
		cout << ")";
	}

    if (s == "name") {
        cout << " " << name; 
    }
}

double& VectorND::operator [] (int index)
{   return this->A[index%(this->n)];    }

double  VectorND::operator [] (int index) const
{   return this->A[index%(this->n)];    }






















class MatrixVectorND {

private:
    int m, n;
    VectorND * * A;
    string name;
public:
    MatrixVectorND() {};
    void MatrixVector3D(int m, int n, string s) {

        this->m = m;
        this->n = n;
        this->name = s;

        this->A = (VectorND **) malloc (m * sizeof(VectorND*));
        if (this->A == NULL) 
            cerr << "\nNo Memory for " << name << endl;
        else {
            for (int i = 0; i < m; i++) {
                this->A[i] = (VectorND *) malloc (n * sizeof(VectorND));
                if (this->A[i] != NULL) 
                    for (int j = 0; j < n; j++) {
                        string mat = "(" + to_string(i) + ", " + to_string(j) + ")";
                        this->A[i][j].initZeroVectorND(3, mat);
                    }
                else {
                    cout << "\nNo Memory for " << name << endl;
                }
            }
        }
    };

    ~MatrixVectorND() {

        for (int i = 0; i < m; i++) {
            free(A[i]);
            A[i] = NULL;
        }

        free(A);
        A = NULL;

        //cout << "\n-->Destroyed MatrixVectorND := " << name << endl;
    };

    void updateVector3D(int i, int j, double x, double y, double z) {

        this->A[i][j].updateVector3D(x, y, z);
    }

    void dilate(int i, int j, const VectorND& head, const VectorND& source, double lambda) {

        this->A[i][j].dilate(head, source, lambda);
    }

    void escMatrixVectorND(string s) {

        if (s == "info") {
            cout << "\nName := " << name << endl;
            cout << "\nMatrix dimensions m := " << m << "  n := " << n << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << "  ";
                    A[i][j].escVectorND("info");
                }
                cout << "\n";
            }
        }

        if (s == "matrix") {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << "  ";
                    A[i][j].escVectorND("matrix");
                }
                cout << "\n";
            }
        }

        if (s == "name") {
            cout << "\nName := " << name << endl;
            
        }
    }


    VectorND*  operator [] (int index) const
    {   return this->A[index%(this->n)];    }
    
};

#endif