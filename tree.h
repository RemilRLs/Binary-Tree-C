#pragma once

typedef struct sTreeNode {
	int m_data;

	struct sTreeNode* childLeft;
	struct sTreeNode* childRight;
}node;

node* creerNoeudArbre(int p_value);
void libererArbre(node** p_ppRoot);
void ajoutGauche(node* p_pRoot, int p_value);
void ajoutDroite(node* p_pRoot, int p_value);
int hauteur(node* p_pRoot);
int taille(node* p_pRoot);
int nbFeuilles(node* p_pRoot);
void supprSousArbre(node** p_ppRoot, int p_value);

// Course Section

void parcoursPrefixe(node* p_pRoot);
void parcoursInfixe(node* p_pRoot);
void parcoursPostfixe(node* p_pRoot);



