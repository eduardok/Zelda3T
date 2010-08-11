/*

    Zelda Time to Triumph

    Copyright (C) 2007-2009  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#include "Poissons.h"

Poissons::Poissons(Jeu* jeu) : gpJeu(jeu), page(0) {
    image = SDL_CreateRGBSurface(SDL_HWSURFACE, 320, 240, 32, 0, 0, 0, 0);
    imageCadre = IMG_Load("data/images/menu/cadres.png");
}

Poissons::~Poissons() {
    SDL_FreeSurface(image);
    SDL_FreeSurface(imageCadre);
}

void Poissons::draw(SDL_Surface* gpScreen) {
    SDL_Rect dst; dst.x = 0; dst.y = 0;
    SDL_BlitSurface(image, NULL, gpScreen, &dst);
}

void Poissons::init() {
    fond();
}

void Poissons::fond() {
    SDL_Rect src; src.w = 16; src.h = 16;
    SDL_Rect dst;
    
    src.x = 16; src.y = 16;
    for (int j = 0; j < 240; j+=16)
        for (int i = 0; i < 320; i+=16) {
            dst.x = i; dst.y = j; SDL_BlitSurface(imageCadre, &src, image, &dst);
        }
        
    src.x = 0; src.y = 0; dst.x = 16; dst.y = 0; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    src.x = 0; src.y = 16; dst.x = 16; dst.y = 16; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    src.x = 0; src.y = 32; dst.x = 16; dst.y = 32; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    
    for (int i = 0; i < 4; i++) {
        src.x = 16; src.y = 0; dst.x = 32+16*i; dst.y = 0; 
        SDL_BlitSurface(imageCadre, &src, image, &dst);
        src.x = 16; src.y = 64; dst.x = 32+16*i; dst.y = 16; 
        SDL_BlitSurface(imageCadre, &src, image, &dst);
        src.x = 16; src.y = 32; dst.x = 32+16*i; dst.y = 32; 
        SDL_BlitSurface(imageCadre, &src, image, &dst);
    }
    
    src.x = 32; src.y = 0; dst.x = 112-16; dst.y = 0; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    src.x = 32; src.y = 16; dst.x = 112-16; dst.y = 16; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    src.x = 32; src.y = 32; dst.x = 112-16; dst.y = 32; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    
    
    ostringstream os; os << (page+1);
    gpJeu->affiche(image, "FISHES "+os.str(), 40, 17);
    
    placeCadres();
    
    /*gpJeu->setStop(true);
    gpEnnemi->draw(image);
    gpJeu->setStop(false);
    
    delete gpEnnemi;
    gpEnnemi = new Ennemi(gpJeu, 0, 0, 0, true);*/
}

void Poissons::placeCadres() {
    switch (page) {
        case 0 :
            cadre(16,48,0); cadre(64,48,88,32,0);
            cadre(168,48,2); cadre(216,48,88,32,2);
            cadre(16,96,14); cadre(64,96,88,32,14);
            cadre(16,144,22); cadre(64,144,88,32,22);
            cadre(168,144,24); cadre(216,144,88,32,24);
            break;
        case 1 :
            cadre(16,48,11); cadre(64,48,88,32,11);
            cadre(168,48,7); cadre(216,48,88,32,7);
            cadre(16,144,16); cadre(64,144,88,32,16);
            cadre(168,144,19); cadre(216,144,88,32,19);
            cadre(16,192,28); cadre(64+8,192,88,32,28);
            break;
        case 2 :
            cadre(16,48,3); cadre(64,48,88,32,3);
            cadre(168,48,4); cadre(216,48,88,32,4);
            cadre(16,96,10); cadre(64,96,88,32,10);
            cadre(16,144,17); cadre(64,144,88,32,17);
            cadre(168,144,21); cadre(216,144,88,32,21);
            cadre(16,192,26); cadre(64+8,192,88,32,26);
            break;
        case 3 :
            cadre(16,48,8); cadre(64,48,88,32,8);
            cadre(168,48,12); cadre(216,48,88,32,12);
            cadre(16,144,20); cadre(64,144,88,32,20);
            cadre(168,144,23); cadre(216,144,88,32,23);
            cadre(16,192,29); cadre(64+8,192,88+16,32,29);
            break;
        case 4 :
            cadre(16,48,5); cadre(64,48,88,32,5);
            cadre(168,48,9); cadre(216,48,88,32,9);
            cadre(16,96,13); cadre(64,96,88,32,13);
            cadre(16,144,15); cadre(64,144,88,32,15);
            cadre(16,192,25); cadre(64+8,192,88,32,25);
            break;
        case 5 :
            cadre(16,48,1); cadre(64,48,88,32,1);
            cadre(168,48,6); cadre(216,48,88,32,6);
            cadre(16,144,18); cadre(64,144,88,32,18);
            cadre(16,192,27); cadre(64+8,192,88,32,27);
            break;
    }
}

void Poissons::cadre(int x, int y, int id) {
    
    
    int type = 0;
    if (id > 14) type++;
    if (id > 24) type++;
    
    SDL_Rect src;
    src.x=0; src.y=96+type*32; src.w = 32+type*8; src.h = 32;
    
    SDL_Rect dst;
    dst.x=x; dst.y=y;
    
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    
    if (!gpJeu->getJoueur()->getPoisson(id)) return;
    
    switch (id+9) {
        case P_ECREVISSE : src.w = 16; src.h = 16; src.x=0; src.y=102; break;
        case P_EPERLAN : src.w = 16; src.h = 16; src.x=16; src.y=102; break;
        case P_POISSON_ZEBRE : src.w = 16; src.h = 16; src.x=32; src.y=102; break;
        case P_GOBIE : src.w = 16; src.h = 16; src.x=48; src.y=102; break;
        case P_CRABE : src.w = 16; src.h = 16; src.x=64; src.y=102; break;
        case P_PIBALE : src.w = 16; src.h = 16; src.x=80; src.y=102; break;
        case P_VAIRON : src.w = 16; src.h = 16; src.x=96; src.y=102; break;
        case P_CARASSIN_DORE : src.w = 16; src.h = 16; src.x=112; src.y=102; break;
        case P_ABLETTE : src.w = 16; src.h = 16; src.x=128; src.y=102; break;
        case P_GOUJON : src.w = 16; src.h = 16; src.x=144; src.y=102; break;
        case P_LOCHE : src.w = 16; src.h = 16; src.x=160; src.y=102; break;
        case P_EPINOCHE : src.w = 16; src.h = 16; src.x=176; src.y=102; break;
        case P_GREMILLE : src.w = 16; src.h = 16; src.x=192; src.y=102; break;
        case P_BLENNIE : src.w = 16; src.h = 16; src.x=208; src.y=102; break;
        case P_MAGICARPE : src.w = 16; src.h = 16; src.x=224; src.y=102; break;
        case P_TRUITE : src.w = 24; src.h = 16; src.x=0; src.y=119; break;
        case P_AYU : src.w = 24; src.h = 16; src.x=24; src.y=119; break;
        case P_PERCHE_NOIRE : src.w = 24; src.h = 16; src.x=48; src.y=119; break;
        case P_ANGUILLE : src.w = 24; src.h = 16; src.x=72; src.y=119; break;
        case P_POISSON_CHAT : src.w = 24; src.h = 16; src.x=96; src.y=119; break;
        case P_BLACK_BASS : src.w = 24; src.h = 16; src.x=120; src.y=119; break;
        case P_HUCHON : src.w = 24; src.h = 16; src.x=144; src.y=119; break;
        case P_BARBEAU : src.w = 24; src.h = 16; src.x=168; src.y=119; break;
        case P_LAMPROIE : src.w = 24; src.h = 16; src.x=192; src.y=119; break;
        case P_HOTU : src.w = 24; src.h = 16; src.x=216; src.y=119; break;
        case P_SAUMON : src.w = 32; src.h = 16; src.x=0; src.y=136; break;
        case P_ESTURGEON : src.w = 32; src.h = 16; src.x=32; src.y=136; break;
        case P_OMBLE_CHEVALIER : src.w = 32; src.h = 16; src.x=64; src.y=136; break;
        case P_CARPE : src.w = 32; src.h = 16; src.x=96; src.y=136; break;
        case P_SILURE : src.w = 32; src.h = 16; src.x=128; src.y=136; break;
    }
    dst.x=x+8; dst.y=y+8;
    SDL_BlitSurface(gpJeu->getImageObjets(), &src, image, &dst);
}

void Poissons::cadre(int x, int y, int w, int h, int id) {
    SDL_Rect src; src.w = 16; src.h = 16;
    SDL_Rect dst;
    
    for (int j = y+16; j < y+h-16; j+=16)
        for (int i = x+16; i < x+w-16; i+=16) {
            src.x = 16; src.y = 64; dst.x = i; dst.y = j; 
            SDL_BlitSurface(imageCadre, &src, image, &dst);
        }
    
    //haut et bas
    for (int i = x+16; i < x+w-16; i+=16) {
        src.x = 16; src.y = 48; dst.x = i; dst.y = y; 
        SDL_BlitSurface(imageCadre, &src, image, &dst);
        src.x = 16; src.y = 80; dst.x = i; dst.y = y+h-16; 
        SDL_BlitSurface(imageCadre, &src, image, &dst);
    }
    
    //gauche et droite
    for (int j = y+16; j < y+h-16; j+=16) {
        src.x = 0; src.y = 64; dst.x = x; dst.y = j; 
        SDL_BlitSurface(imageCadre, &src, image, &dst);
        src.x = 32; src.y = 64; dst.x = x+w-16; dst.y = j;
        SDL_BlitSurface(imageCadre, &src, image, &dst);
    }
    
    //haut gauche
    src.x = 0; src.y = 48; dst.x = x; dst.y = y; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    
    //haut droite
    src.x = 32; src.y = 48; dst.x = x+w-16; dst.y = y; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    
    //bas gauche
    src.x = 0; src.y = 80; dst.x = x; dst.y = y+h-16; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    
    //bas droite
    src.x = 32; src.y = 80; dst.x = x+w-16; dst.y = y+h-16; 
    SDL_BlitSurface(imageCadre, &src, image, &dst);
    
    if (gpJeu->getJoueur()->getPoisson(id)) {
        switch (id) {
            case 0 : gpJeu->affiche(image, "Crawfish", x+8, y+8); break;
            case 1 : gpJeu->affiche(image, "Smelt", x+8, y+8); break;
            case 2 : gpJeu->affiche(image, "Zebrafish", x+8, y+8); break;
            case 3 : gpJeu->affiche(image, "Goby", x+8, y+8); break;
            case 4 : gpJeu->affiche(image, "Crab", x+8, y+8); break;
            case 5 : gpJeu->affiche(image, "Eel larvae", x+8, y+8); break;
            case 6 : gpJeu->affiche(image, "Minnow", x+8, y+8); break;
            case 7 : gpJeu->affiche(image, "Goldfish", x+8, y+8); break;
            case 8 : gpJeu->affiche(image, "Bleak", x+8, y+8); break;
            case 9 : gpJeu->affiche(image, "Gudgeon", x+8, y+8); break;
            case 10 : gpJeu->affiche(image, "Loach", x+8, y+8); break;
            case 11 : gpJeu->affiche(image, "Stickleback", x+8, y+8); break;
            case 12 : gpJeu->affiche(image, "Ruffe", x+8, y+8); break;
            case 13 : gpJeu->affiche(image, "Blenny", x+8, y+8); break;
            case 14 : gpJeu->affiche(image, "Magikarp", x+8, y+8); break;
            case 15 : gpJeu->affiche(image, "Trout", x+8, y+8); break;
            case 16 : gpJeu->affiche(image, "Ayu", x+8, y+8); break;
            case 17 : gpJeu->affiche(image, "Black perch", x+8, y+8); break;
            case 18 : gpJeu->affiche(image, "Eel", x+8, y+8); break;
            case 19 : gpJeu->affiche(image, "Catfish", x+8, y+8); break;
            case 20 : gpJeu->affiche(image, "Largemouth", x+8, y+8); break;
            case 21 : gpJeu->affiche(image, "Huchen", x+8, y+8); break;
            case 22 : gpJeu->affiche(image, "Barbell", x+8, y+8); break;
            case 23 : gpJeu->affiche(image, "Lamprey", x+8, y+8); break;
            case 24 : gpJeu->affiche(image, "Nase", x+8, y+8); break;
            case 25 : gpJeu->affiche(image, "Salmon", x+8, y+8); break;
            case 26 : gpJeu->affiche(image, "Sturgeon", x+8, y+8); break;
            case 27 : gpJeu->affiche(image, "Arctic charr", x+8, y+8); break;
            case 28 : gpJeu->affiche(image, "Carp", x+8, y+8); break;
            case 29 : gpJeu->affiche(image, "Brown bullhead", x+8, y+8); break;
        }
    } else gpJeu->affiche(image, "???", x+8, y+8);
}

bool Poissons::isVide() {
    Joueur* gpJoueur = gpJeu->getJoueur();
    switch (page) {
        case 0 :
            if (gpJoueur->getPoisson(0) || gpJoueur->getPoisson(2) || gpJoueur->getPoisson(14)
            || gpJoueur->getPoisson(22) || gpJoueur->getPoisson(24))
                return false;
            break;
        case 1 :
            if (gpJoueur->getPoisson(11) || gpJoueur->getPoisson(7) || gpJoueur->getPoisson(16)
            || gpJoueur->getPoisson(19) || gpJoueur->getPoisson(28))
                return false;
            break;
        case 2 :
            if (gpJoueur->getPoisson(3) || gpJoueur->getPoisson(4) || gpJoueur->getPoisson(10)
            || gpJoueur->getPoisson(17) || gpJoueur->getPoisson(21) || gpJoueur->getPoisson(26))
                return false;
            break;
        case 3 :
            if (gpJoueur->getPoisson(8) || gpJoueur->getPoisson(12) || gpJoueur->getPoisson(20)
            || gpJoueur->getPoisson(23) || gpJoueur->getPoisson(29))
                return false;
            break;
        case 4 :
            if (gpJoueur->getPoisson(5) || gpJoueur->getPoisson(9) || gpJoueur->getPoisson(13)
            || gpJoueur->getPoisson(15) || gpJoueur->getPoisson(25))
                return false;
            break;
        case 5 :
            if (gpJoueur->getPoisson(1) || gpJoueur->getPoisson(6) || gpJoueur->getPoisson(18)
            || gpJoueur->getPoisson(27))
                return false;
            break;
    }
    return true;
}

void Poissons::verif(int sens) {
    if (sens == 0) {while (isVide()) {page--; if (page < 0) page = 5;}}
    else {while (isVide()) {page++; if (page > 5) page = 0;}}
}

void Poissons::moveL() {page--; verif(0); init();}

void Poissons::moveR() {page++; verif(1); init();}

void Poissons::setPage(int i) {
    page = i; if (page < 0) page = 0; if (page > 3) page = 3; verif(1);
}
