#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief ll_newLinkedList: Crea y retorna un nuevo LinkedList. Es el constructor, ya que en él daremos valores iniciales a
 *                           las variables y asignaremos las funciones a sus punteros.
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this= NULL;

	this = (LinkedList*)malloc(sizeof(LinkedList));
	if (this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief ll_len: Retorna la cantidad de elementos de la lista.
 *  \param this LinkedList*: Puntero a la lista.
 *  \return int Retorna (-1) si el puntero es NULL
 *          o la cantidad de elementos de la listas si todo salio bien.
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

	if(this!=NULL)
	{
		returnAux = this->size;
	}
	return returnAux;
}
/** \brief Node* getNode: Obtiene un nodo de la lista, retorna un puntero al nodo que se encuentra en el índice especificado.
 *                        Verificando que el puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 * \param this LinkedList*: Puntero a la lista
 * \param int nodeIndex: Indice del nodo a obtener.
 * \return Node* Retorna (NULL) Error: Si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente retorna el puntero al nodo.
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pAuxNode = NULL;
		int i;

		if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
		{
			pAuxNode = this->pFirstNode;//indice 0
			for(i=0;i<nodeIndex;i++)
			{
				pAuxNode = pAuxNode->pNextNode;
			}
		}
	    return pAuxNode;
}

/** \brief _getNode:  Permite realizar el test de la funcion getNode la cual es privada.
 * \param LinkedList* this: Puntero a la lista
 * \param int nodeIndex: Indice del nodo a obtener.
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente.
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}
/** \brief addNode: Agrega y enlaza un nuevo nodo a la lista
 *  \param LinkedList* this: Puntero a la lista.
 *  \param int nodeIndex: Ubicacion donde se agregara el nuevo nodo
 *  \param void* pElement: Puntero al elemento a ser contenido por el nuevo nodo
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente.
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* newNode;
	Node* prevNode;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		newNode = (Node*)malloc(sizeof(Node));
		if(newNode != NULL)
		{
			newNode->pElement = pElement;
			if(nodeIndex == 0) //si es el primer nodo
			{
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;
			}
			else
			{
				prevNode = getNode(this,nodeIndex-1);//obtengo el nodo anterior
				if(prevNode != NULL)
				{
					newNode->pNextNode = prevNode->pNextNode;//me guardo el next node en el nuevo
					prevNode->pNextNode = newNode;//pNextNode = ESTE NODO
				}
			}
			this->size++;//INCREMENTO
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief test_addNode: Permite realizar el test de la funcion addNode la cual es privada.
 *  \param LinkedList* this: Puntero a la lista.
 *  \param int nodeIndex: Ubicacion donde se agregara el nuevo nodo.
 *  \param void* pElement: Puntero al elemento a ser contenido por el nuevo nodo.
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}
/** \brief ll_add: Agrega un elemento a LinkedList. Verificando que el puntero this sea distinto de NULL.
 *  \param LinkedList* this: Puntero a la lista.
 *  \param void* pElement: Puntero al elemento a ser agregado.
 *  \return int Retorna (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	if(this != NULL)
	{
		if(addNode(this,ll_len(this),pElement)==0)//Agrega un nodo al final
		{
			returnAux = 0;
		}
	}
	return returnAux;
}
/** \brief ll_get: Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
                   puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 *  \param LinkedList* this: Puntero a la lista.
 *  \param int index: Ubicacion del elemento a obtener.
 *  \return void* Retorna :(NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista).
 *                         (pElement) Si funciono correctamente.
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodeAux;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodeAux = getNode(this,index);
    	if(pNodeAux != NULL)
    	{
    		returnAux = pNodeAux->pElement;
    	}
    }
    return returnAux;
}
/** \brief ll_set: Inserta un elemento en el LinkedList, en el índice especificado. Verificando que el puntero this
                   sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 * \param LinkedList* this: Puntero a la lista.
 * \param int index: Ubicacion del elemento a modificar.
 * \param void* pElement: Puntero al nuevo elemento.
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
	Node *pNodeAux;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		pNodeAux = getNode(this, index);
		if (pNodeAux != NULL)
		{
			pNodeAux->pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}
/** \brief ll_remove: Elimina un elemento del LinkedList, en el índice especificado. Verificando que el puntero this
                      sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 * \param this LinkedList*: Puntero a la lista
 * \param nodeIndex int: Ubicacion del elemento a eliminar
 * \return int Retorna: (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeAux;
    Node* pPrevNode;

    if(this != NULL && index>= 0 && index < ll_len(this))
    {
		pNodeAux = getNode(this,index);
		if(pNodeAux != NULL)
		{
			if(index == 0)
			{
				this->pFirstNode = pNodeAux->pNextNode;
			} else {
				pPrevNode = getNode(this,index-1);
				if(pPrevNode != NULL)
				{
					pPrevNode->pNextNode = pNodeAux->pNextNode;
				}
			}
			free(pNodeAux);
			this->size--;
			returnAux = 0;
		}
    }
    return returnAux;
}
/** \brief ll_clear: Borra todos los elementos de LinkedList. Verificando que el puntero this sea distinto de NULL.
 * \param this LinkedList*: Puntero a la lista.
 * \return int Retorna: (-1) Error: si el puntero a la lista es NULL.
 *                      ( 0) Si funciono correctamente.
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
		for(int i = 0;i<ll_len(this);i++)
		{
			if(ll_remove(this,i) == 0)
			{
				returnAux = 0;
			} else {
				returnAux = -1;
				break;
			}
		}
    }
    return returnAux;
}
/** \brief ll_deleteLinkedList: Elimina el LinkedList .Verifica que el puntero this sea distinto de NULL.
 * \param this LinkedList*: Puntero a la lista.
 * \return int Retorna:  (-1) Error: si el puntero a la lista es NULL.
 *                      ( 0) Si funciono correctamente.
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
		if(ll_clear(this)==0)
		{
			free(this);
			returnAux = 0;
		}
    }
    return returnAux;
}
/** \brief ll_indexOf: Busca y retorna el índice de la primera aparición de un elemento (pElement) pasado como parametro en el LinkedList.
                       Verificando que el puntero this sea distinto de NULL.
 * \param this LinkedList*: Puntero a la lista
 * \param pElement void*: Puntero al elemento
 * \return int Retorna: (-1) Error: si el puntero a la lista es NULL
 *                      (indice del elemento) Si funciono correctamente
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pAuxNode;
    int i;

    if(this != NULL)
    {
		for(i=0; i<ll_len(this);i++)
		{
			pAuxNode = getNode(this,i);
			if(pAuxNode != NULL && pAuxNode->pElement == pElement)
			{
				returnAux = i;
				break;
			}
		}
    }
    return returnAux;
}
/** \brief ll_isEmpty: Indica si la lista esta o no vacia. Verificando que el puntero this sea distinto de NULL.
 * \param this LinkedList*: Puntero a la lista
 * \return int Retorna: (-1) Error: si el puntero a la lista es NULL
 *                      ( 0) Si la lista NO esta vacia
 *                      ( 1) Si la lista esta vacia
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
	{
		if(ll_len(this) == 0)
		{
			returnAux = 1;
		}
        else
        {
			returnAux = 0;
		}
	}
    return returnAux;
}
/** \brief ll_push: Desplaza los elementos e inserta un nuevo elemento en la lista en la posicion indicada. Verificando que el puntero this sea
                   distinto de NULL y que index sea positivo e inferior al tamaño del array.
 * \param this LinkedList*: Puntero a la lista
 * \param nodeIndex int: Ubicacion donde se agregara el nuevo elemento
 * \param pElement void*: Puntero al nuevo elemento
 * \return int Retorna: (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index>=0 && index<=ll_len(this))
    {
    	if(addNode(this,index,pElement)==0)
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}
/** \brief ll_pop: Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina de la lista.
                   Verificando que el puntero this sea distinto de NULL y que index sea positivo inferior al tamaño del array.
 * \param this LinkedList*: Puntero a la lista
 * \param nodeIndex int: Ubicacion del elemento eliminar
 * \return void* Retorna: (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                        (pElement) Si funciono correctamente
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pElementAux;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
    	pElementAux = ll_get(this,index);
		if (pElementAux != NULL)
		{
			if(ll_remove(this,index)==0)
			{
				returnAux = pElementAux;
			}
		}
    }
    return returnAux;
}
/** \brief ll_contains: Determina si la lista contiene o no el elemento pasado como parametro. Verificando que tanto el pElement
                        y this sea distintos de NULL.
 * \param this LinkedList*: Puntero a la lista.
 * \param pElement void*: Puntero del elemento a verificar.
 * \return int Retorna: (-1) Error: si el puntero a la lista es NULL.
 *                      ( 1) Si contiene el elemento.
 *                      ( 0) si No contiene el elemento.
 */
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
		if(ll_indexOf(this,pElement)!=-1)
		{
			returnAux = 1;
		} else {
			returnAux = 0;
		}
    }
    return returnAux;
}
/** \brief ll_containsAll:  Determina si todos los elementos de la lista (this2), estan contenidos en la lista (this).
                            Verificando que tanto el puntero this como pList2 sean distintos de NULL.
 * \param this LinkedList*: Puntero a la lista.
 * \param this2 LinkedList*: Puntero a la lista.
 * \return int Retorna: (-1) Error: si alguno de los punteros a las listas son NULL.
 *                      ( 1) Si los elementos de (this2) estan contenidos en la lista (this).
 *                      ( 0) si los elementos de (this2) NO estan contenidos en la lista (this).
 */
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement;
    int i;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1; // si no entra al if, retorna 1, no encontro ningun elemento que no estuviera en la lista
    	for(i=0; i<ll_len(this2);i++)
    	{
    		pElement = ll_get(this2, i);
    		if(pElement != NULL && ll_contains(this, pElement) == 0)//si el elemento no esta
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}
/** \brief ll_subList: Crea y retorna una nueva lista con los elementos indicados. Verificando que el puntero this
                       sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño del array.
 * \param pList LinkedList*: Puntero a la lista.
 * \param from int: Indice desde el cual se copian los elementos en la nueva lista.
 * \param to int: Indice hasta el cual se copian los elementos en la nueva lista (no incluido).
 * \return LinkedList* Retorna: (NULL) Error: si el puntero a la lista es NULL
 *                              o (si el indice from es menor a 0 o mayor al len de la lista)
 *                              o (si el indice to es menor o igual a from o mayor al len de la lista)
 *                              (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;

    if(this != NULL && from >= 0 && from <= ll_len(this) && to >= 0 && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	if (cloneArray != NULL)
    	{
			for(i=from;i<to;i++)
			{
				pElement = ll_get(this, i);
				if(pElement != NULL)
				{
					ll_add(cloneArray,pElement);
				}
			}
    	}
    }
    return cloneArray;
}
/** \brief ll_clone: Crea y retorna un nuevo LinkedList copia del LinkedList original. Verificando que el puntero this sea
                     distinto de NULL.
 * \param pList LinkedList*: Puntero a la lista
 * \return LinkedList* Retorna: (NULL) Error: si el puntero a la lista es NULL
 *                              (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}
/** \brief ll_sort: Ordena los elementos del array recibiendo como parámetro la función que sera la encargada de determinar
                    que elemento es mas grande que otro y si se debe ordenar de manera ascendente o descendente.
                    Verificando que tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL.
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 *                      ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
	int i;
	int flagDisorder = 1;
	int len = ll_len(this);
	int sortBy;
	void* pElement;
	void* pElement2;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		while (flagDisorder==1)
		{
			flagDisorder = 0;
			for (i = 0; i < len- 1; i++)
			{
				pElement = ll_get(this,i);
				pElement2 = ll_get(this,i+1);
				sortBy = pFunc(pElement,pElement2);
				if ((order == 1 && sortBy == 1) || (order == 0 && sortBy == -1))
				{
					ll_set(this,i,pElement2);
					ll_set(this,i+1,pElement);
					flagDisorder = 1;
				}
			}
		}
		returnAux = 0;
	}
    return returnAux;
}
/** \brief ll_map: Itera la lista y utiliza a la funcion criterio pasada por parametro en cada iteracion.
                   Verificando que tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL.
 * \param this LinkedList*: Puntero a la lista
 * \param (*pFunc) int: Puntero a la funcion criterio
 * \return int Retorna: (-1) Error: si el puntero a la listas es NULL
 *                      ( 0) Si todo ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int returnAux=-1;
	int len = ll_len(this);
	void *pElement=NULL;
	if(this!=NULL && pFunc!=NULL )
	{
		for(int i=0;i<len;i++)
		{
			pElement=ll_get(this, i);
			if(pElement!=NULL && !pFunc(pElement))
			{
				returnAux=0;
			}
		}
	}
	return returnAux;
}
/** \brief ll_filter: Filtra la lista usando a la funcion criterio recibida como parametro.
                      Verificando que tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL.
 * \param this LinkedList*: Puntero a la lista.
 * \param (*pFunc) int: Puntero a la funcion criterio.
 * \return int Retorna: (-1) Error: si el puntero a la listas es NULL
 *                      ( 0) Si todo ok
 */
int ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	int returnAux = -1;
	void* pElement = NULL;
	int criterio;
	int i;

	if(this != NULL && pFunc != NULL)
	{
		for(i=ll_len(this)-1; i >= 0; i--)
		{
			pElement = ll_get(this,i);
			if(pElement != NULL)
			{
				criterio = pFunc(pElement);
				if(criterio == 0)
				{
					returnAux = ll_remove(this,i);
				}
			}
		}
	}
	return returnAux;
}
/** \brief ll_reduceInt: Reduce la lista a un numero de tipo entero, usando a la funcion criterio recibida como parametro.
                         Verificando que tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL.
 * \param this LinkedList*: Puntero a la lista.
 * \param (*pFunc) int: Puntero a la funcion criterio.
 * \param pResultado int: Puntero donde se escribe el resultado.
 * \return int Retorna: (-1) Error: si el puntero a la listas es NULL
 *                      ( 0) Si todo ok
 */
int ll_reduceInt(LinkedList* this, int (*pFunc)(void*), int* pResultado)
{
	int returnAux=-1;
	int len = ll_len(this);
	int counter=0;
	void* pElement=NULL;
	if(this!=NULL && pFunc!=NULL && len>-1)
	{
		for(int i=0;i<len;i++)
		{
			pElement = ll_get(this, i);
			counter=+ pFunc(pElement);
		}
		*pResultado = counter;
		returnAux=0;
	}
	return returnAux;
}
/** \brief ll_reduceFloat: Reduce la lista a un numero de tipo flotante, usando a la funcion criterio recibida como parametro.
                           Verificando que tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL.
 * \param this LinkedList*: Puntero a la lista.
 * \param (*pFunc) int: Puntero a la funcion criterio.
 * \param pResultado int: Puntero donde se escribe el resultado.
 * \return int Retorna: (-1) Error: si el puntero a la listas es NULL
 *                      ( 0) Si todo ok
 */
int ll_reduceFloat(LinkedList* this, int (*pFunc)(void*), float* pResultado)
{
	int returnAux=-1;
	int len = ll_len(this);
	float counter=0;
	void* pElement=NULL;
	if(this!=NULL && pFunc!=NULL && len>-1)
	{
		for(int i=0;i<len;i++)
		{
			pElement = ll_get(this, i);
			counter=+ pFunc(pElement);
		}
		*pResultado = counter;
		returnAux=0;
	}
	return returnAux;
}
