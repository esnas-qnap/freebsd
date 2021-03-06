//===-- lsan_flags.inc ------------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// LSan runtime flags.
//
//===----------------------------------------------------------------------===//
#ifndef LSAN_FLAG
# error "Define LSAN_FLAG prior to including this file!"
#endif

// LSAN_FLAG(Type, Name, DefaultValue, Description)
// See COMMON_FLAG in sanitizer_flags.inc for more details.

LSAN_FLAG(bool, report_objects, false,
          "Print addresses of leaked objects after main leak report.")
LSAN_FLAG(
    int, resolution, 0,
    "Aggregate two objects into one leak if this many stack frames match. If "
    "zero, the entire stack trace must match.")
LSAN_FLAG(int, max_leaks, 0, "The number of leaks reported.")
LSAN_FLAG(int, exitcode, 23,
          "If nonzero kill the process with this exit code upon finding leaks.")

// Flags controlling the root set of reachable memory.
LSAN_FLAG(bool, use_globals, true,
          "Root set: include global variables (.data and .bss)")
LSAN_FLAG(bool, use_stacks, true, "Root set: include thread stacks")
LSAN_FLAG(bool, use_registers, true, "Root set: include thread registers")
LSAN_FLAG(bool, use_tls, true,
          "Root set: include TLS and thread-specific storage")
LSAN_FLAG(bool, use_root_regions, true,
          "Root set: include regions added via __lsan_register_root_region().")

LSAN_FLAG(bool, use_unaligned, false, "Consider unaligned pointers valid.")
LSAN_FLAG(bool, use_poisoned, false,
          "Consider pointers found in poisoned memory to be valid.")
LSAN_FLAG(bool, log_pointers, false, "Debug logging")
LSAN_FLAG(bool, log_threads, false, "Debug logging")
LSAN_FLAG(const char *, suppressions, "", "Suppressions file name.")
