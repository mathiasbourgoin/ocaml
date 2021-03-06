/***********************************************************************/
/*                                                                     */
/*                                OCaml                                */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

#include <mlvalues.h>
#include <memory.h>
#include <signals.h>
#include "unixsupport.h"

CAMLprim value unix_chown(value path, value uid, value gid)
{
  CAMLparam1(path);
  char * p;
  int ret;
  p = caml_stat_alloc_string(path);
  caml_enter_blocking_section();
  ret = chown(p, Int_val(uid), Int_val(gid));
  caml_leave_blocking_section();
  caml_stat_free(p);
  if (ret == -1) uerror("chown", path);
  CAMLreturn(Val_unit);
}
