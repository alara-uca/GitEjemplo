/**
 * @file    <modulo>.h
 * @brief   <Descripción de una línea de lo que hace el módulo.>
 *
 * @author      Alejandro Lara Doña - alejandro.lara@uca.es
 * @date        2026
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 */

#ifndef <MODULO>_H
#define <MODULO>_H

#include "tipos.h"

// ===== <Modulo> - Constantes Publicas =====
/**
 * @brief <Qué parametriza este enumerado.>
 * @ingroup <Modulo>
 */
enum <modulo>_config {
  <MODULO>_<CONSTANTE> = 0,   //!< <Descripción y unidades.>
};

// ===== <Modulo> - Tipos Publicos =====
/**
 * @brief <Qué representa este tipo.>
 * @ingroup <Modulo>
 */
typedef enum {
  <MODULO>_<VALOR>,           //!< <Descripción.>
} <modulo>_estado_t;

// ===== <Modulo> - Funciones Publicas =====
void <modulo>_inicializar(void);

#endif // <MODULO>_H
