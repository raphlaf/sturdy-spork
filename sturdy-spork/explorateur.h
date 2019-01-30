#pragma once

#include <CL/cl.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

class explorateur
{
public:
	explorateur(double x_debut = -2.0f, double y_debut = -2.0f, double x_fin = 2.0f, double y_fin = 2.0f, int largeur = 500, int hauteur = 500, int nombre_iter_max = 1000, bool utiliser_opencl = true);
	~explorateur();

	void calcul_image();

	std::string device_info();


	int* prendre_image();
	int get_max_iter() { return nombre_iter_max; }

	int get_width() { return largeur; }
	int get_height() { return hauteur; }

private:
	double x_debut, y_debut; //position du coin en bas � gauche de l'image dans le plan complexe
	double x_fin, y_fin;     //position du coin en haut � droite de l'image dans le plan complexe
	int largeur, hauteur;    //dimensions de l'image

	int nombre_iter_max; //nombre maximal d'it�rations pour le calcul z <- z^2 + c

	bool utiliser_opencl; //choix d'utilisation de OpenCL ou du CPU

	int* image_courante;

	std::vector<cl::Platform> platformes; //vecteur des diff�rentes platformes OpenCL sur la machine
	
	cl::Platform platforme_courante;  //platforme OpenCL pr�sentement utilis�e
	std::vector<cl::Device> devices; //vecteur des diff�rents devices disponibles sur la platforme pr�sentement utilis�e

	cl::Device device_utilise;

	cl::Program::Sources sources;
	cl::Context contexte;
	cl::Program programme;
	cl::Kernel kernel;


};

