#pragma once

#include <CL/cl.hpp>
#include <vector>

class explorateur
{
public:
	explorateur(double x_debut = -2.0f, double y_debut = -2.0f, double x_fin = 2.0f, double y_fin = 2.0f, int largeur = 500, int hauteur = 500, int nombre_iter_max = 250, bool utiliser_opencl = false);
	~explorateur();

	int* calcul_image();

private:
	double x_debut, y_debut; //position du coin en bas à gauche de l'image dans le plan complexe
	double x_fin, y_fin;     //position du coin en haut à droite de l'image dans le plan complexe
	int largeur, hauteur;    //dimensions de l'image

	int nombre_iter_max; //nombre maximal d'itérations pour le calcul z <- z^2 + c

	bool utiliser_opencl; //choix d'utilisation de OpenCL ou du CPU

	std::vector<cl::Platform> platformes; //vecteur des différentes platformes OpenCL sur la machine
	
	cl::Platform platforme_courante;  //platforme OpenCL présentement utilisée
	std::vector<cl::Device>* devices; //vecteur des différents devices disponibles sur la platforme présentement utilisée

	cl::Program::Sources sources;
	cl::Context contexte;
	cl::Program programme;
	cl::Kernel kernel;
	cl::CommandQueue queue;


};

