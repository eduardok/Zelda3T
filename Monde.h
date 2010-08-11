/*

    Zelda Time to Triumph

    Copyright (C) 2007-2009  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#ifndef __MONDE_H__
#define __MONDE_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Jeu;

class Monde {
    public :
        Monde(Jeu* jeu);
        ~Monde();
        void changeZone(int newZone);
        int motifValue(int x, int y);
        int motifAirValue(int x, int y);
        int murValue(int x, int y);
        int contenuValue(int x, int y);
        int regionValue(int i);
        void drawSol(SDL_Surface* screen, int phg[2]);
        void drawAir(SDL_Surface* screen, int phg[2]);
        void setValeur(int x, int y, int vsol, int vair, int vmur, int vcontenu=-1);
        void setValeur(int x, int y, int vsol, int vmur=999);
        void transitZone(int nzone, int decx, int decy, Direction dir);
        void transitSalle(Direction dir);
        void transitFull(int nzone, int nx, int ny, int dir=-1);
        void transitTemps(int nzone, int nx, int ny, int dir=-1);
        void transitTempsRetour();
        void defilTransit(SDL_Surface* gpScreen);
        void passage(int x, int y, int id);
        void setMap(int x, int y, int val);
        void setAir(int x, int y, int val);
        void setMurs(int x, int y, int val);
        void setContenu(int x, int y, int val);
        int etage();
        void replace();
        void permuteBlocs();
        void detRegion(int newZone);
        int getUtile();
        void setUtile(int i);
        void rempli(int x, int y, int la, int lo);
        void vide(int x, int y, int la, int lo);
        int getLargeur();
        int getHauteur();
        bool isChangeTemps();
        void barque(int pos, bool visible);
        void wagon(int pos, bool visible);
        void animCafe();
    private :
        void chargeMap(int zone);
        void corrigeMap(int zone); //ajoute les coffres, les portes ouvertes, etc.
        void initMatrice(int zone); //ajoute objets et ennemis
        void saveOldMap(); // sauvegarde la map � quitter pour restauration future
        void restoreOldMap();
        
        int largeur;
        int hauteur;
        int plafondmax; // nb de montif de air � afficher
        int anim;
        int animold;
        int utile; //utile sur certaines maps ex : pierres du d�sert (OLB)
        int musique;
        Jeu* gpJeu;
        int animtransX;
        int animtransY;
        int animtransC;
        int animtransT;
        int niveau;
        int charge;
        int avion;
        int ovni;
        int ecl1;
        int ecl2;
        int xecl1;
        int xecl2;
        int xfiltre;
        int yfiltre;
        double afiltre;
        int region[4];     //phg et pbd de la r�gion visit�
        int map[400][400]; // map des motifs du dessous
        int mur[800][800]; // map des collisions
        int air[400][400]; // map des motifs du dessus
        int contenu[400][400]; // map avec contenu des coffres, des pancartes, etc.
        int plafond[336][2]; // motifs de air � afficher
        int transMap[42][32]; //pour transition
        int transAir[42][32];
        
        int mapOld[400][400]; // map des motifs du dessous
        int murOld[800][800]; // map des collisions
        int airOld[400][400]; // map des motifs du dessus
        int contenuOld[400][400]; // map avec contenu des coffres, des pancartes, etc.
        
        SDL_Surface* image[7]; // image motifs
        SDL_Surface* imagetransit;
        SDL_Surface* imagelevel;
        SDL_Surface* imageSpe[19]; //image fond, pluie, etc.
        Uint32 lastAnimTime; // date de la derni�re anim
        
        
        //� virer
        int spec[420][420];
};

#endif  // Monde.h
