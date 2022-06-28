#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){

     returnAux = this->size;


    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* AuxNode=NULL;

	int i;


	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		AuxNode = this->pFirstNode;
		for(i=0;i<nodeIndex;i++){
			AuxNode = AuxNode->pNextNode;
		}
	}

    return AuxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* AuxNodeA;
	Node* AuxNodeB;
	Node* AuxNodeC;
	int len;
	int returnAux = -1;
	len = ll_len(this);
	if(this != NULL && nodeIndex <= len && nodeIndex >= 0){

		AuxNodeC = (Node*) malloc(sizeof(Node));
		if(AuxNodeC != NULL){
			AuxNodeC->pElement = pElement;
			AuxNodeC->pNextNode = NULL;
		}
		if(nodeIndex == 0){
			AuxNodeC->pNextNode = this->pFirstNode;
			this->pFirstNode = AuxNodeC;
			this->size++;
			returnAux = 0;
		}
		else{
			AuxNodeB = (Node*) getNode(this, nodeIndex-1);
			AuxNodeA = AuxNodeB->pNextNode;
			AuxNodeB->pNextNode = AuxNodeC;
			AuxNodeC->pNextNode = AuxNodeA;
			this->size++;
			returnAux = 0;

		}

	}
		return returnAux;

}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL){
    	addNode(this,ll_len(this), pElement);
		returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	Node* p=NULL;
	 void* returnAux = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	p = (Node*) malloc(sizeof(Node));
    	p = (Node*) getNode(this, index);
    	if(p != NULL){
    		returnAux = p->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	Node* AuxNodeB;
	int len;
	int returnAux = -1;
	len = ll_len(this);
	if(this != NULL && index < len && index >= 0){
		if(index == 0){
			this->pFirstNode->pElement = pElement;
			returnAux = 0;
		}
		else{
			AuxNodeB = (Node*) getNode(this, index-1);
			AuxNodeB->pNextNode->pElement = pElement;
			returnAux = 0;
		}
	}
		return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    Node* auxA=NULL;
    Node* auxB=NULL;
    int returnAux = -1;

    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) != 0){
    	auxA = (Node*) getNode(this,index);
        if (index == 0){
            this->pFirstNode = auxA->pNextNode;
            free(auxA);
            this->size--;
            returnAux = 0;
        }
        else{
        	auxB = (Node*) getNode(this,(index-1));
        	if(index > 0 ){
            auxB->pNextNode = auxA->pNextNode;
            free(auxA);
            this->size--;
            returnAux = 0;
        	}
        }
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;

    len = ll_len(this);
    if(this != NULL){
    	for(i=0;i<len;i++){
    		ll_remove(this, i);
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;

    len = ll_len(this);
    if(this != NULL){
    	for(i=0;i<len;i++){
    		ll_remove(this, i);
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	Node* p;
    int returnAux = -1;
    int i;

    if(this != NULL){
    	for(i=0;i<ll_len(this);i++){
    		p = (Node*) ll_get(this, i);
    		if(p == pElement){
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = 1;
    	if(ll_len(this) != 0){
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);
    if(this != NULL && index >=0 && index <= len){
    	returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	Node* p;
    void* returnAux = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && index >=0 && index <= len){
    	p = ll_get(this, index);
    	ll_remove(this, index);
    	returnAux = p;
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = 0;
    	if(ll_indexOf(this, pElement) != -1){
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	Node* p;
	Node* y;
    int returnAux = -1;
    int i;
    int j;
    int c=0;
    int len;
    int len2;

    len = ll_len(this);
    len2 = ll_len(this2);
    if(this != NULL && this2 != NULL){
    	returnAux = 0;
    	for(i=0;i<len;i++){
    		for(j=0;j<len2;j++){
    			p = ll_get(this, i);
    			y = ll_get(this2, j);
    			if( p == y){
    				c++;
    			}
    		}
    	}
    	if(c == len2){
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* cloneArray = NULL;
	void* pElement;
	int i;

	if ((this != NULL) && (from >= 0 && ll_len(this) >= to)){
		cloneArray = ll_newLinkedList();
		for(i=from;i<to;i++){
			pElement = ll_get(this,i);
			ll_add(cloneArray,pElement);
		}
	}
	return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL){
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	Node* AuxNode;
	Node* AuxNodeB;
	void* p = NULL;
	int returnAux = -1;
	int i;
	int flag_A;

	if(this != NULL && pFunc != NULL && (order == 1 || order == 0) && ll_len(this)> 0 ){
		do{
			i = 0;
			AuxNode = (Node*) getNode(this,i);
			flag_A = 0;
			for(i=0;i<ll_len(this)-1;i++){
				if(i != 0){
					AuxNode = AuxNode->pNextNode;
				}
				if( (order == 0 && AuxNode->pElement != NULL && AuxNode->pNextNode->pElement != NULL && (*pFunc)(AuxNode->pElement,AuxNode->pNextNode->pElement)== -1) ||
					(order == 1 && AuxNode->pElement != NULL && AuxNode->pNextNode->pElement != NULL && (*pFunc)(AuxNode->pElement,AuxNode->pNextNode->pElement)== 1)){
					AuxNodeB = AuxNode->pNextNode;
			        p = AuxNode->pElement;
			        AuxNode->pElement = AuxNodeB->pElement;
			        AuxNodeB->pElement = p;
			        returnAux = 0;
			        flag_A = 1;
				}
			}
		}while(flag_A == 1);
	returnAux = 0;
	}
return returnAux;
}

