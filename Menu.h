/*

    Zelda Time to Triumph

    Copyright (C) 2007-2009  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#ifndef __MENU_H__
#define __MENU_H__

#include <SDL/SDL.h>

class Jeu;

class Menu {
    public :
        Menu(Jeu* jeu);
        ~Menu();
        void draw(SDL_Surface* gpScreen);
        void menuIn();
        void menuOut();
        int getVal();
    private :
        void drawCadres(SDL_Surface* gpScreen);
        void drawEquipe(SDL_Surface* gpScreen);
        void drawCoeur(SDL_Surface* gpScreen);
        void drawCristaux(SDL_Surface* gpScreen);
        void drawGemme(SDL_Surface* gpScreen);
        void drawStatut(SDL_Surface* gpScreen);
        void drawInventaire(SDL_Surface* gpScreen);
        void drawCurseur(SDL_Surface* gpScreen);
        SDL_Surface* imageCadre;
        SDL_Surface* imageCoeur;
        SDL_Surface* imageObjets;
        SDL_Surface* imageInventaire;
        SDL_Surface* imageGemme;
        Jeu* gpJeu;
        int sens;
        int val;
        int anim;
        Uint32 lastAnimTime;
};

#endif  // Menu.h
