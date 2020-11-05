/*
 * utn.c
 *
 *  Created on: 3/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"

#define BUFFER_STRING 4096


static int getString(char* string, int len);
static int getInt(int* integer);
static int getFloat(float * decimalNumber);
static int getText(char* text, int len);
static int getAlphaNumeric(char* text, int len);
static int getMail(char* text, int len);
static int getAlphanumericDots(char* text, int len);

//////////////Functions designed to request data from a user////////////////

/**
 * \brief Requests the user to enter a number (integer)
 * \param int *pNumber, pointer to the space where the value obtained will be left
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param int min, minimum value allowed
 * \param int max, maximum value allowed
 * \param int retries, number of opportunities to enter the data
 * \return (-1) -1 (0) 0
 */
int utn_getNumber(int *pNumber, char *message, char *errorMessage, int min,	int max, int retries)
{
    int retorno = -1;
    int auxInt;

    if (pNumber != NULL && message != NULL && errorMessage != NULL && min < max && max > min && retries > 0)
    {
        while (retries > 0)
        {
            printf("%s", message);
            if (getInt(&auxInt) == -1 || (auxInt < min || auxInt > max))
            {
                printf("%s", errorMessage);
                retries--;
            }
            else
            {
                *pNumber = auxInt;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Requests the user to enter a number (decimal number)
 * \param float *pNumber, pointer to the space where the value obtained will be left
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param float min, minimum value allowed
 * \param float max, maximum value allowed
 * \param int retries, number of opportunities to enter the data
 * \return (-1) -1 (0) 0
 */
int utn_getFloatNumber(float *pNumber, char *message, char *errorMessage,float min, float max, int retries)
{
    int retorno = -1;
    float auxFloat;

    if (pNumber != NULL && message != NULL && errorMessage != NULL && min < max	&& max > min && retries > 0)
    {
        while (retries > 0)
        {
            printf("%s", message);
            if (getFloat(&auxFloat) == -1 || (auxFloat < min || auxFloat > max))
            {
                printf("%s", errorMessage);
                retries--;
            }
            else
            {
                *pNumber = auxFloat;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Requests the user to enter a string (only letters)
 * \param char *name, pointer to the space where the value obtained will be left
 * \param int len, size of name
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param int retries, number of opportunities to enter the data
 * \return (-1) -1 (0) 0
 */
int utn_getName(char* name, int len, char* message, char* errorMessage, int retries)
{
    int retorno = -1;
    char auxName[BUFFER_STRING];

    if(name!=NULL && message!=NULL && errorMessage!=NULL && retries>0)
    {
        while(retries>0)
        {
            printf("%s",message);
            if(getText(auxName,sizeof(auxName))==0 && strnlen(auxName,sizeof(auxName))<len)
            {
                retorno = 0;
                strncpy(name,auxName,len);
                break;
            }
            else
            {
                printf("%s",errorMessage);
                retries--;
            }
        }
    }
    return retorno;
}
/**
 * \brief Requests the user to enter a string (letters or numbers)
 * \param char *name, pointer to the space where the value obtained will be left
 * \param int len, size of name
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param int retries, number of opportunities to enter the data
 * \return (-1) -1 (0) 0
 */
int utn_getAlphanumeric(char *name, int len, char *message, char *errorMessage, int retries)
{
    int retorno = -1;
    char auxName[BUFFER_STRING];

    if (name != NULL && message != NULL && errorMessage != NULL && retries > 0)
    {
        while (retries > 0)
        {
            printf("%s", message);
            if (getAlphaNumeric(auxName, sizeof(auxName)) == 0 && strnlen(auxName, sizeof(auxName)) < len)
            {
                retorno = 0;
                strncpy(name, auxName, len);
                break;
            }
            else
            {
                printf("%s", errorMessage);
                retries--;
            }
        }
    }
    return retorno;
}
/**
 * \brief Requests the user to enter a e-mail domain
 * \param char *name, pointer to the space where the value obtained will be left
 * \param int len, size of name
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param int retries, number of opportunities to enter the data
 * \return (-1) -1 (0) 0
 */
int utn_getMail(char *name, int len, char *message, char *errorMessage, int retries)
{
    int retorno = -1;
    char auxName[BUFFER_STRING];

    if (name != NULL && message != NULL && errorMessage != NULL	&& retries > 0)
    {
        while (retries > 0)
        {
            printf("%s", message);
            if (getMail(auxName, sizeof(auxName)) == 0 && strnlen(auxName, sizeof(auxName)) < len)
            {
                retorno = 0;
                strncpy(name, auxName, len);
                break;
            }
            else
            {
                printf("%s", errorMessage);
                retries--;
            }
        }
    }
    return retorno;
}
/**
 * \brief Requests the user to enter a id card number. It can be used for web domains as well.
 * \param char *name, pointer to the space where the value obtained will be left
 * \param int len, size of name
 * \param char *message, message to be shown to the user
 * \param char *errorMessage, message to be shown to the user
 * \param int retries, number of opportunities to enter the data
 * \return (-1) -1 (0) 0
 */
int utn_getIdentityDocument(char *name, int len, char *message, char *errorMessage, int retries)
{
    int retorno = -1;
    char auxName[BUFFER_STRING];

    if (name != NULL && message != NULL && errorMessage != NULL	&& retries > 0)
    {
        while (retries > 0)
        {
            printf("%s", message);
            if (getAlphanumericDots(auxName, sizeof(auxName)) == 0 && strnlen(auxName, sizeof(auxName)) < len)
            {
                retorno = 0;
                strncpy(name, auxName, len);
                break;
            }
            else
            {
                printf("%s", errorMessage);
                retries--;
            }
        }
    }
    return retorno;
}
//////////////Functions that obtain data and validates.////////////////

/**
 * \brief Gets a string of characters
 * \param char* string, pointer to the string where it leaves the obtained
 * \param int len, size of the string that it receives
 * \return (-1) -1 (0) 0
 */
static int getString(char *string, int len)
{

    int retorno = -1;
    char aux[BUFFER_STRING];

    if (string != NULL && len > 0)
    {
        fflush(stdin); //WINDOWS
        //__fpurge(stdin); //LINUX
        //fpurge(stdin); //MACOS
        fgets(aux, sizeof(aux), stdin);
        if(aux[strnlen(aux, sizeof(aux)) - 1] == '\n')
        {
            aux[strnlen(aux, sizeof(aux)) - 1] = '\0';
        }

        if(aux[0] == '\0')
        {
            retorno = -1;
        }
        else if(strnlen(aux, sizeof(aux)) <= len)
        {
            strncpy(string, aux, len);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Gets an integer and validates it
 * \param int* integer, pointer to the space where it leaves the obtained
 * \return (-1) -1 (0) 0
 */
static int getInt(int* integer)
{
    int retorno = -1;
    char aux[BUFFER_STRING];

    if(integer!=NULL)
    {
        if(getString(aux,sizeof(aux))== 0 && isValidNumber(aux,sizeof(aux)))
        {
            *integer = atoi(aux);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Gets a decimal number and validates it
 * \param float* decimalNumber, pointer to the space where it leaves the obtained
 * \return (-1) -1 (0) 0
 */
static int getFloat(float * decimalNumber)
{
    int retorno = -1;
    char aux[BUFFER_STRING];

    if(decimalNumber!= NULL)
    {
        if(getString(aux,sizeof(aux))== 0 && isValidNumberFloat(aux,sizeof(aux)))
        {
            *decimalNumber = atof(aux);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Gets a text of only letters and validates it
 * \param char* text, pointer to the space where it leaves the obtained
 * \return (-1) -1 (0) 0
 */
static int getText(char* text, int len)
{
    int retorno = -1;
    char aux[BUFFER_STRING];

    if(text!= NULL && len>0)
    {
        if(getString(aux,sizeof(aux))== 0 && isValidLetters(aux,sizeof(aux)) && (strnlen(aux,sizeof(aux))<len))
        {
            strncpy(text,aux,len);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Gets a text of letters and numbers and validates it
 * \param char* text, pointer to the space where it leaves the obtained
 * \return (-1) -1 (0) 0
 */
static int getAlphaNumeric(char* text, int len)
{
    int retorno = -1;
    char aux[BUFFER_STRING];

    if(text!= NULL && len>0)
    {
        if(getString(aux,sizeof(aux))== 0 && isValidAlphaNumeric(aux,sizeof(aux)) && (strnlen(aux,sizeof(aux))<len))
        {
            strncpy(text,aux,len);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Gets a text and validates it to match a valid e-mail
 * \param char* text, pointer to the space where it leaves the obtained
 * \return (-1) -1 (0) 0
 */
static int getMail(char* text, int len)
{
    int retorno = -1;
    char aux[BUFFER_STRING];

    if(text!= NULL && len>0)
    {
        if(getString(aux,sizeof(aux))== 0 && isValidMail(aux,sizeof(aux)) && (strnlen(aux,sizeof(aux))<len))
        {
            strncpy(text,aux,len);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Gets a text and validates it to allow letters, numbers, dots and hyphens
 * \param char* text, pointer to the space where it leaves the obtained
 * \return (-1) -1 (0) 0
 */
static int getAlphanumericDots(char* text, int len)
{
    int retorno = -1;
    char aux[BUFFER_STRING];

    if(text!= NULL && len>0)
    {
        if(getString(aux,sizeof(aux))== 0 && isValidDocumentNumber(aux,sizeof(aux)) && (strnlen(aux,sizeof(aux))<len))
        {
            strncpy(text,aux,len);
            retorno = 0;
        }
    }
    return retorno;
}

