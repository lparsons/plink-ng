#ifndef __PLINK2_LD_H__
#define __PLINK2_LD_H__

// This file is part of PLINK 2.00, copyright (C) 2005-2018 Shaun Purcell,
// Christopher Chang.
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include "plink2_common.h"

#ifdef __cplusplus
namespace plink2 {
#endif

FLAGSET_DEF_START()
  kfLdPrune0,
  kfLdPruneWindowBp = (1 << 0),
  kfLdPrunePairwise = (1 << 1),
  kfLdPrunePairphase = (1 << 2)
FLAGSET_DEF_END(ld_prune_t);
// todo: old multicollinearity test; new multiallelic option

FLAGSET_DEF_START()
  kfLdConsole0,
  kfLdConsoleDosage = (1 << 0),
  kfLdConsoleHweMidp = (1 << 1)
FLAGSET_DEF_END(ld_console_t);

typedef struct ld_info_struct {
  double prune_last_param; // VIF or r^2 threshold
  ld_prune_t prune_modifier;
  uint32_t prune_window_size;
  uint32_t prune_window_incr;
  ld_console_t ld_console_modifier;
  char* ld_console_varids[2];
} ld_info_t;

void init_ld(ld_info_t* ldip);

void cleanup_ld(ld_info_t* ldip);

pglerr_t ld_prune(const uintptr_t* orig_variant_include, const chr_info_t* cip, const uint32_t* variant_bps, const char* const* variant_ids, const uintptr_t* variant_allele_idxs, const alt_allele_ct_t* maj_alleles, const double* allele_freqs, const uintptr_t* founder_info, const uintptr_t* sex_male, const ld_info_t* ldip, uint32_t raw_variant_ct, uint32_t variant_ct, uint32_t raw_sample_ct, uint32_t founder_ct, uint32_t max_thread_ct, pgen_reader_t* simple_pgrp, char* outname, char* outname_end);

pglerr_t ld_console(const uintptr_t* variant_include, const chr_info_t* cip, const char* const* variant_ids, const uintptr_t* variant_allele_idxs, const char* const* allele_storage, const uintptr_t* founder_info, const uintptr_t* sex_nm, const uintptr_t* sex_male, const ld_info_t* ldip, uint32_t variant_ct, uint32_t raw_sample_ct, uint32_t founder_ct, pgen_reader_t* simple_pgrp);

#ifdef __cplusplus
} // namespace plink2
#endif

#endif // __PLINK2_LD_H__
