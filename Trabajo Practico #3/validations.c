/*
 * validations.c
 *
 *  Created on: 3/11/2020
 *      Author: TORRES CAICEDO ANDRES FELIPE
 */
#include <stdio.h>
#include <stdlib.h>
#include "validations.h"


#define TRUE 1
#define FALSE 0

/**
 * \brief Validates that what you receive it is valid to a letter or hyphen.
 * \param char *string, pointer to the string to be validated
 * \return (0) FALSE (1) TRUE (-1) -1
 */
int isValidCompoundName(char* string, int len)
{
    int i ;
    int retorno = -1;

    if(string!= NULL)
    {
        retorno = TRUE;
        for(i=0; string[i]!= '\0' && i < len; i++)
        {
            if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z')
            		&& (string[i] != '-' || string[0] == '-') && (string[i] != ' '))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Validates that what you receive it is a letter. Contemplates spaces.
 * \param char *string, pointer to the string to be validated
 * \return (0) FALSE (1) TRUE (-1) -1
 */
int isValidLetters(char* string, int len)
{
    int i ;
    int retorno = -1;

    if(string!= NULL && len > 0)
    {
        retorno = TRUE;
        for(i=0; string[i]!= '\0' && i < len; i++)
        {
            if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' '))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Validates that what it receives is a number.
 * 		  Contemplates both negatives and positives.
 * \param char *num, pointer to the string to be validated
 * \return (0) FALSE (1) TRUE (-1) -1
 */
int isValidNumber(char* num, int len)
{
    int retorno = -1;
    int i = 0;

    if(num!= NULL && len > 0)
    {
        retorno = TRUE;
        if(num[0] == '-' || num[0] == '+')
        {
            i = 1;
        }
        for( ; num[i]!= '\0' && i < len; i++)
        {
            if(num[i] < '0' || num[i] > '9')
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Validates that what it receives is a number.
 * 		  Contemplates both negative and positive and decimal.
 * \param char *num, pointer to the string to be validated
 * \return (0) FALSE (1) TRUE (-1) -1
 */
int isValidNumberFloat(char* num,int len)
{
    int retorno = -1;
    int i = 0;
    int counterDot = 0;

    if(num!= NULL && len > 0)
    {
        retorno=TRUE;
        if(num[0] == '-' || num[0] == '+')
        {
            i = 1;
        }
        for( ; num[i]!= '\0' && i < len; i++)
        {
            if(num[i] < '0' || num[i] > '9')
            {
                if(num[i] == '.')
                {
                    counterDot++;
                    if(counterDot>1)
                    {
                        retorno = FALSE;
                        break;
                    }
                }
                else
                {
                    retorno = FALSE;
                    break;
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief Validates that what you receive it is a letter or a number.
 * 		  Contemplates spaces.
 * \param char *string, pointer to the string to be validated
 * \return (0) FALSE (1) TRUE (-1) -1
 */
int isValidAlphaNumeric(char* string, int len)
{
    int i ;
    int retorno = -1;

    if(string!= NULL && len > 0)
    {
        retorno = TRUE;
        for(i=0; string[i]!= '\0' && i < len; i++)
        {
            if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' ') && (string[i] < '0' || string[i] > '9'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Validates that what you receive it is valid to a letter, number, dot or hyphen.
 * \param char *string, pointer to the string to be validated
 * \return (0) FALSE (1) TRUE (-1) -1
 */
int isValidDocumentNumber(char* string, int len)
{
    int i ;
    int retorno = -1;

    if(string!= NULL && len > 0)
    {
        retorno = TRUE;
        for(i=0; string[i]!= '\0' && i < len; i++)
        {
            if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z')  && (string[i] < '0' || string[i] > '9')
                    && (string[i] != '.' || string[0] == '.') && (string[i] != '-' || string[0] == '-'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Validates that what you receive it is a valid mail.
 * \param char *string, pointer to the string to be validated
 * \return (0) FALSE (1) TRUE (-1) -1
 */
int isValidMail(char* string, int len)
{
    int i ;
    int retorno = -1;
    int counterAt=0;

    if(string!= NULL && len > 0)
    {
        retorno = TRUE;
        for(i=0; string[i]!= '\0' && i < len; i++)
        {
            if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z')  && (string[i] < '0' || string[i] > '9')
                    && (string[i] != '.' || string[0] == '.') && (string[i] != '-' || string[0] == '-') && (string[i] != '_' || string[0] == '_'))
            {
                if(string[i] == '@')
                {
                    counterAt++;
                    if(counterAt>1 || string[0] == '@')
                    {
                        retorno = FALSE;
                        break;
                    }
                }
                else
                {
                    retorno = FALSE;
                    break;
                }
            }
        }
    }
    return retorno;
}

