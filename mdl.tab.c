/* A Bison parser, made from mdl.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	COMMENT	257
# define	DOUBLE	258
# define	LIGHT	259
# define	CONSTANTS	260
# define	SAVE_COORDS	261
# define	CAMERA	262
# define	SPHERE	263
# define	TORUS	264
# define	BOX	265
# define	LINE	266
# define	CS	267
# define	MESH	268
# define	STRING	269
# define	SET	270
# define	MOVE	271
# define	SCALE	272
# define	ROTATE	273
# define	BASENAME	274
# define	SAVE_KNOBS	275
# define	TWEEN	276
# define	FRAMES	277
# define	VARY	278
# define	PUSH	279
# define	POP	280
# define	SAVE	281
# define	GENERATE_RAYFILES	282
# define	SHADING	283
# define	SHADING_TYPE	284
# define	SETKNOBS	285
# define	FOCAL	286
# define	DISPLAY	287

#line 1 "mdl.y"

  /* C declarations */
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "matrix.h"

  SYMTAB *s;
  struct light *l;
  struct constants *c;
  struct command op[MAX_COMMANDS];
  struct matrix *m;
  int lastop=0;
  int lineno=0;
#define YYERROR_VERBOSE 1

  
#line 22 "mdl.y"
#ifndef YYSTYPE
typedef union{
  double val;
  char string[255];

} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		151
#define	YYFLAG		-32768
#define	YYNTBASE	34

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 287 ? yytranslate[x] : 36)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     1,     4,     6,    15,    21,    26,    38,    41,
      49,    55,    62,    69,    77,    84,    92,   100,   109,   117,
     126,   135,   145,   153,   162,   171,   181,   190,   200,   210,
     221,   224,   228,   233,   237,   243,   248,   253,   257,   260,
     263,   269,   272,   279,   281,   283,   285,   288,   291,   294,
     297
};
static const short yyrhs[] =
{
      -1,    34,    35,     0,     3,     0,     5,    15,     4,     4,
       4,     4,     4,     4,     0,    17,     4,     4,     4,    15,
       0,    17,     4,     4,     4,     0,     6,    15,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     7,    15,
       0,     8,     4,     4,     4,     4,     4,     4,     0,     9,
       4,     4,     4,     4,     0,     9,     4,     4,     4,     4,
      15,     0,     9,    15,     4,     4,     4,     4,     0,     9,
      15,     4,     4,     4,     4,    15,     0,    10,     4,     4,
       4,     4,     4,     0,    10,     4,     4,     4,     4,     4,
      15,     0,    10,    15,     4,     4,     4,     4,     4,     0,
      10,    15,     4,     4,     4,     4,     4,    15,     0,    11,
       4,     4,     4,     4,     4,     4,     0,    11,     4,     4,
       4,     4,     4,     4,    15,     0,    11,    15,     4,     4,
       4,     4,     4,     4,     0,    11,    15,     4,     4,     4,
       4,     4,     4,    15,     0,    12,     4,     4,     4,     4,
       4,     4,     0,    12,     4,     4,     4,    15,     4,     4,
       4,     0,    12,     4,     4,     4,     4,     4,     4,    15,
       0,    12,     4,     4,     4,    15,     4,     4,     4,    15,
       0,    12,    15,     4,     4,     4,     4,     4,     4,     0,
      12,    15,     4,     4,     4,    15,     4,     4,     4,     0,
      12,    15,     4,     4,     4,     4,     4,     4,    15,     0,
      12,    15,     4,     4,     4,    15,     4,     4,     4,    15,
       0,    14,    15,     0,    14,    15,    15,     0,    14,    15,
      15,    15,     0,    16,    15,     4,     0,    18,     4,     4,
       4,    15,     0,    18,     4,     4,     4,     0,    19,    15,
       4,    15,     0,    19,    15,     4,     0,    20,    15,     0,
      21,    15,     0,    22,     4,     4,    15,    15,     0,    23,
       4,     0,    24,    15,     4,     4,     4,     4,     0,    25,
       0,    28,     0,    26,     0,    27,    15,     0,    29,    30,
       0,    31,     4,     0,    32,     4,     0,    33,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,    40,    41,    44,    45,    65,    78,    89,   112,   121,
     136,   150,   164,   178,   194,   210,   225,   241,   258,   275,
     293,   310,   329,   348,   367,   385,   404,   423,   442,   462,
     482,   491,   501,   512,   521,   532,   543,   568,   591,   598,
     605,   615,   622,   633,   639,   645,   651,   658,   665,   672,
     679
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "COMMENT", "DOUBLE", "LIGHT", "CONSTANTS", 
  "SAVE_COORDS", "CAMERA", "SPHERE", "TORUS", "BOX", "LINE", "CS", "MESH", 
  "STRING", "SET", "MOVE", "SCALE", "ROTATE", "BASENAME", "SAVE_KNOBS", 
  "TWEEN", "FRAMES", "VARY", "PUSH", "POP", "SAVE", "GENERATE_RAYFILES", 
  "SHADING", "SHADING_TYPE", "SETKNOBS", "FOCAL", "DISPLAY", "input", 
  "command", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    34,    34,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     0,     2,     1,     8,     5,     4,    11,     2,     7,
       5,     6,     6,     7,     6,     7,     7,     8,     7,     8,
       8,     9,     7,     8,     8,     9,     8,     9,     9,    10,
       2,     3,     4,     3,     5,     4,     4,     3,     2,     2,
       5,     2,     6,     1,     1,     1,     2,     2,     2,     2,
       1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       1,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    45,     0,    44,     0,     0,     0,    50,     2,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,    38,    39,     0,
      41,     0,    46,    47,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    33,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     6,    35,    36,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     5,    34,    40,     0,     0,     0,     0,
      11,    12,    14,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     9,    13,    15,    16,    18,     0,    22,
       0,     0,     0,     4,     0,    17,    19,    20,    24,    23,
      26,     0,     0,    21,    25,    28,    27,     0,    29,     7,
       0,     0
};

static const short yydefgoto[] =
{
       1,    29
};

static const short yypact[] =
{
  -32768,     0,-32768,   -14,   -11,    23,    11,    -2,    26,    30,
      31,    24,    25,    38,    39,    29,    34,    35,    47,    48,
      40,-32768,-32768,    41,-32768,    27,    49,    50,-32768,-32768,
      54,    55,-32768,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,-32768,-32768,    70,
  -32768,    71,-32768,-32768,-32768,-32768,    72,    73,    74,    75,
      77,    78,    79,    80,    81,    82,    83,    76,-32768,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    99,    32,   100,-32768,    97,    98,-32768,   101,
     102,   103,   104,   105,   106,   107,   110,   111,   113,   114,
     115,   116,    33,-32768,-32768,-32768,   118,   119,   120,   121,
  -32768,   112,   117,   122,   124,   125,   126,   127,   129,   130,
  -32768,   131,   132,-32768,-32768,-32768,   123,   128,   133,   134,
     135,   136,   137,-32768,   138,-32768,-32768,   139,-32768,   140,
     141,   142,   143,-32768,-32768,-32768,   144,   146,-32768,-32768,
     145,-32768
};

static const short yypgoto[] =
{
  -32768,-32768
};


#define	YYLAST		159


static const short yytable[] =
{
     150,    30,    34,     2,    31,     3,     4,     5,     6,     7,
       8,     9,    10,    35,    11,    33,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      36,    26,    27,    28,    38,    40,   100,   118,    32,    42,
      43,    37,    44,    45,    46,    39,    41,   101,   119,    47,
      48,    49,    50,    54,    55,    51,    52,    53,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      67,    78,    79,    80,    81,    82,    83,    84,    86,    87,
       0,    85,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    88,    89,    99,   102,     0,   106,   107,   108,   109,
       0,   111,   103,   104,   112,   113,   105,   114,   115,   116,
     117,   110,   120,   121,   122,   123,   126,   124,   127,   128,
     129,   130,   125,   131,   132,   133,   134,   137,   135,   139,
     140,   141,   142,   136,     0,   151,   146,   147,     0,   138,
     149,     0,     0,     0,   143,   144,   145,     0,     0,   148
};

static const short yycheck[] =
{
       0,    15,     4,     3,    15,     5,     6,     7,     8,     9,
      10,    11,    12,    15,    14,     4,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       4,    31,    32,    33,     4,     4,     4,     4,    15,    15,
      15,    15,     4,     4,    15,    15,    15,    15,    15,    15,
      15,     4,     4,     4,     4,    15,    15,    30,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    -1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      15,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      -1,    15,     4,     4,     4,     4,     4,     4,     4,     4,
       4,    15,    15,     4,     4,    -1,     4,     4,     4,     4,
      -1,     4,    15,    15,     4,     4,    15,     4,     4,     4,
       4,    15,     4,     4,     4,     4,     4,    15,     4,     4,
       4,     4,    15,     4,     4,     4,     4,     4,    15,     4,
       4,     4,     4,    15,    -1,     0,     4,     4,    -1,    15,
       4,    -1,    -1,    -1,    15,    15,    15,    -1,    -1,    15
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 315 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 3:
#line 45 "mdl.y"
{;
    break;}
case 4:
#line 48 "mdl.y"
{
  lineno++;
  l = (struct light *)malloc(sizeof(struct light));
  l->l[0]= yyvsp[-5].val;
  l->l[1]= yyvsp[-4].val;
  l->l[2]= yyvsp[-3].val;
  l->l[3]= 0;
  l->c[0]= yyvsp[-2].val;
  l->c[1]= yyvsp[-1].val;
  l->c[2]= yyvsp[0].val;
  op[lastop].opcode=LIGHT;
  op[lastop].op.light.c[0] = yyvsp[-2].val; 
  op[lastop].op.light.c[1] = yyvsp[-1].val;
  op[lastop].op.light.c[2] = yyvsp[0].val;
  op[lastop].op.light.c[3] = 0;
  op[lastop].op.light.p = add_symbol(yyvsp[-6].string,SYM_LIGHT,l);
  lastop++;
;
    break;}
case 5:
#line 68 "mdl.y"
{ 
  lineno++;
  op[lastop].opcode = MOVE;
  op[lastop].op.move.d[0] = yyvsp[-3].val;
  op[lastop].op.move.d[1] = yyvsp[-2].val;
  op[lastop].op.move.d[2] = yyvsp[-1].val;
  op[lastop].op.move.d[3] = 0;
  op[lastop].op.move.p = add_symbol(yyvsp[0].string,SYM_VALUE,0);
  lastop++;
;
    break;}
case 6:
#line 80 "mdl.y"
{
  lineno++;
  op[lastop].opcode = MOVE;
  op[lastop].op.move.d[0] = yyvsp[-2].val;
  op[lastop].op.move.d[1] = yyvsp[-1].val;
  op[lastop].op.move.d[2] = yyvsp[0].val;
  op[lastop].op.move.d[3] = 0;
  op[lastop].op.move.p = NULL;
  lastop++;
;
    break;}
case 7:
#line 92 "mdl.y"
{
  lineno++;
  c = (struct constants *)malloc(sizeof(struct constants));
  c->r[0]=yyvsp[-8].val;
  c->r[1]=yyvsp[-7].val;
  c->r[2]=yyvsp[-6].val;
  c->r[3]=0;

  c->g[0]=yyvsp[-5].val;
  c->g[1]=yyvsp[-4].val;
  c->g[2]=yyvsp[-3].val;
  c->g[3]=0;

  c->b[0]=yyvsp[-2].val;
  c->b[1]=yyvsp[-1].val;
  c->b[2]=yyvsp[0].val;
  c->b[3]=0;
  op[lastop].op.constants.p =  add_symbol(yyvsp[-9].string,SYM_CONSTANTS,c);
  op[lastop].opcode=CONSTANTS;
  lastop++;
;
    break;}
case 8:
#line 115 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SAVE_COORDS;
  m = new_matrix(4,4);
  op[lastop].op.save_coordinate_system.p = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 9:
#line 124 "mdl.y"
{
  lineno++;
  op[lastop].opcode = CAMERA;
  op[lastop].op.camera.eye[0] = yyvsp[-5].val;
  op[lastop].op.camera.eye[1] = yyvsp[-4].val;
  op[lastop].op.camera.eye[2] = yyvsp[-3].val;
  op[lastop].op.camera.eye[3] = 0;
  op[lastop].op.camera.aim[0] = yyvsp[-2].val;
  op[lastop].op.camera.aim[1] = yyvsp[-1].val;
  op[lastop].op.camera.aim[2] = yyvsp[0].val;
  op[lastop].op.camera.aim[3] = 0;
  lastop++;
;
    break;}
case 10:
#line 139 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = yyvsp[-3].val;
  op[lastop].op.sphere.d[1] = yyvsp[-2].val;
  op[lastop].op.sphere.d[2] = yyvsp[-1].val;
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = yyvsp[0].val;
  op[lastop].op.sphere.constants = NULL;
  op[lastop].op.sphere.cs = NULL;
  lastop++;
;
    break;}
case 11:
#line 152 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = yyvsp[-4].val;
  op[lastop].op.sphere.d[1] = yyvsp[-3].val;
  op[lastop].op.sphere.d[2] = yyvsp[-2].val;
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = yyvsp[-1].val;
  op[lastop].op.sphere.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.sphere.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 12:
#line 166 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = yyvsp[-3].val;
  op[lastop].op.sphere.d[1] = yyvsp[-2].val;
  op[lastop].op.sphere.d[2] = yyvsp[-1].val;
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = yyvsp[0].val;
  op[lastop].op.sphere.cs = NULL;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.sphere.constants = add_symbol(yyvsp[-4].string,SYM_CONSTANTS,c);
  lastop++;
;
    break;}
case 13:
#line 180 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = yyvsp[-4].val;
  op[lastop].op.sphere.d[1] = yyvsp[-3].val;
  op[lastop].op.sphere.d[2] = yyvsp[-2].val;
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = yyvsp[-1].val;
  op[lastop].op.sphere.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.sphere.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.sphere.constants = add_symbol(yyvsp[-5].string,SYM_CONSTANTS,c);
  lastop++;
;
    break;}
case 14:
#line 197 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = yyvsp[-4].val;
  op[lastop].op.torus.d[1] = yyvsp[-3].val;
  op[lastop].op.torus.d[2] = yyvsp[-2].val;
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = yyvsp[-1].val;
  op[lastop].op.torus.r1 = yyvsp[0].val;
  op[lastop].op.torus.constants = NULL;
  op[lastop].op.torus.cs = NULL;

  lastop++;
;
    break;}
case 15:
#line 212 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = yyvsp[-5].val;
  op[lastop].op.torus.d[1] = yyvsp[-4].val;
  op[lastop].op.torus.d[2] = yyvsp[-3].val;
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = yyvsp[-2].val;
  op[lastop].op.torus.r1 = yyvsp[-1].val;
  op[lastop].op.torus.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.torus.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 16:
#line 227 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = yyvsp[-4].val;
  op[lastop].op.torus.d[1] = yyvsp[-3].val;
  op[lastop].op.torus.d[2] = yyvsp[-2].val;
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = yyvsp[-1].val;
  op[lastop].op.torus.r1 = yyvsp[0].val;
  op[lastop].op.torus.cs = NULL;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.torus.constants = add_symbol(yyvsp[-5].string,SYM_CONSTANTS,c);

  lastop++;
;
    break;}
case 17:
#line 243 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = yyvsp[-5].val;
  op[lastop].op.torus.d[1] = yyvsp[-4].val;
  op[lastop].op.torus.d[2] = yyvsp[-3].val;
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = yyvsp[-2].val;
  op[lastop].op.torus.r1 = yyvsp[-1].val;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.torus.constants = add_symbol(yyvsp[-6].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.torus.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);

  lastop++;
;
    break;}
case 18:
#line 260 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = yyvsp[-5].val;
  op[lastop].op.box.d0[1] = yyvsp[-4].val;
  op[lastop].op.box.d0[2] = yyvsp[-3].val;
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = yyvsp[-2].val;
  op[lastop].op.box.d1[1] = yyvsp[-1].val;
  op[lastop].op.box.d1[2] = yyvsp[0].val;
  op[lastop].op.box.d1[3] = 0;

  op[lastop].op.box.constants = NULL;
  op[lastop].op.box.cs = NULL;
  lastop++;
;
    break;}
case 19:
#line 277 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = yyvsp[-6].val;
  op[lastop].op.box.d0[1] = yyvsp[-5].val;
  op[lastop].op.box.d0[2] = yyvsp[-4].val;
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = yyvsp[-3].val;
  op[lastop].op.box.d1[1] = yyvsp[-2].val;
  op[lastop].op.box.d1[2] = yyvsp[-1].val;
  op[lastop].op.box.d1[3] = 0;

  op[lastop].op.box.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.box.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 20:
#line 295 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = yyvsp[-5].val;
  op[lastop].op.box.d0[1] = yyvsp[-4].val;
  op[lastop].op.box.d0[2] = yyvsp[-3].val;
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = yyvsp[-2].val;
  op[lastop].op.box.d1[1] = yyvsp[-1].val;
  op[lastop].op.box.d1[2] = yyvsp[0].val;
  op[lastop].op.box.d1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.box.constants = add_symbol(yyvsp[-6].string,SYM_CONSTANTS,c);
  op[lastop].op.box.cs = NULL;
  lastop++;
;
    break;}
case 21:
#line 312 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = yyvsp[-6].val;
  op[lastop].op.box.d0[1] = yyvsp[-5].val;
  op[lastop].op.box.d0[2] = yyvsp[-4].val;
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = yyvsp[-3].val;
  op[lastop].op.box.d1[1] = yyvsp[-2].val;
  op[lastop].op.box.d1[2] = yyvsp[-1].val;
  op[lastop].op.box.d1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.box.constants = add_symbol(yyvsp[-7].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.box.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);

  lastop++;
;
    break;}
case 22:
#line 333 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-5].val;
  op[lastop].op.line.p0[1] = yyvsp[-4].val;
  op[lastop].op.line.p0[2] = yyvsp[-3].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-2].val;
  op[lastop].op.line.p1[1] = yyvsp[-1].val;
  op[lastop].op.line.p1[2] = yyvsp[0].val;
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  op[lastop].op.line.cs0 = NULL;
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 23:
#line 351 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-6].val;
  op[lastop].op.line.p0[1] = yyvsp[-5].val;
  op[lastop].op.line.p0[2] = yyvsp[-4].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-2].val;
  op[lastop].op.line.p1[1] = yyvsp[-1].val;
  op[lastop].op.line.p1[2] = yyvsp[0].val;
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol(yyvsp[-3].string,SYM_MATRIX,m);
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 24:
#line 369 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-6].val;
  op[lastop].op.line.p0[1] = yyvsp[-5].val;
  op[lastop].op.line.p0[2] = yyvsp[-4].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-3].val;
  op[lastop].op.line.p1[1] = yyvsp[-2].val;
  op[lastop].op.line.p1[2] = yyvsp[-1].val;
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  op[lastop].op.line.cs0 = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 25:
#line 387 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-7].val;
  op[lastop].op.line.p0[1] = yyvsp[-6].val;
  op[lastop].op.line.p0[2] = yyvsp[-5].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-3].val;
  op[lastop].op.line.p1[1] = yyvsp[-2].val;
  op[lastop].op.line.p1[2] = yyvsp[-1].val;
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol(yyvsp[-4].string,SYM_MATRIX,m);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 26:
#line 407 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-5].val;
  op[lastop].op.line.p0[1] = yyvsp[-4].val;
  op[lastop].op.line.p0[2] = yyvsp[-3].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-2].val;
  op[lastop].op.line.p1[1] = yyvsp[-1].val;
  op[lastop].op.line.p1[2] = yyvsp[0].val;
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol(yyvsp[-6].string,SYM_CONSTANTS,c);
  op[lastop].op.line.cs0 = NULL;
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 27:
#line 425 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-6].val;
  op[lastop].op.line.p0[1] = yyvsp[-5].val;
  op[lastop].op.line.p0[2] = yyvsp[-4].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-2].val;
  op[lastop].op.line.p1[1] = yyvsp[-1].val;
  op[lastop].op.line.p1[2] = yyvsp[0].val;
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol(yyvsp[-7].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol(yyvsp[-3].string,SYM_MATRIX,m);
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 28:
#line 444 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-6].val;
  op[lastop].op.line.p0[1] = yyvsp[-5].val;
  op[lastop].op.line.p0[2] = yyvsp[-4].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-3].val;
  op[lastop].op.line.p1[1] = yyvsp[-2].val;
  op[lastop].op.line.p1[2] = yyvsp[-1].val;
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol(yyvsp[-7].string,SYM_CONSTANTS,yyvsp[-7].string);
  op[lastop].op.line.cs0 = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 29:
#line 464 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-7].val;
  op[lastop].op.line.p0[1] = yyvsp[-6].val;
  op[lastop].op.line.p0[2] = yyvsp[-5].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-3].val;
  op[lastop].op.line.p1[1] = yyvsp[-2].val;
  op[lastop].op.line.p1[2] = yyvsp[-1].val;
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol(yyvsp[-8].string,SYM_CONSTANTS,yyvsp[-8].string);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol(yyvsp[-4].string,SYM_MATRIX,m);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 30:
#line 484 "mdl.y"
{
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,yyvsp[0].string);
  op[lastop].op.mesh.constants = NULL;
  op[lastop].op.mesh.cs = NULL;
  lastop++;
;
    break;}
case 31:
#line 493 "mdl.y"
{ /* name and constants */
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,yyvsp[0].string);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.mesh.constants = add_symbol(yyvsp[-1].string,SYM_CONSTANTS,c);
  op[lastop].op.mesh.cs = NULL;
  lastop++;
;
    break;}
case 32:
#line 503 "mdl.y"
{
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,yyvsp[-1].string);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.mesh.constants = add_symbol(yyvsp[-2].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.mesh.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 33:
#line 514 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SET;
  op[lastop].op.set.p = add_symbol(yyvsp[-1].string,SYM_VALUE,0);
  set_value(op[lastop].op.set.p,yyvsp[0].val);
  op[lastop].op.set.val = yyvsp[0].val;
  lastop++;
;
    break;}
case 34:
#line 523 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SCALE;
  op[lastop].op.scale.d[0] = yyvsp[-3].val;
  op[lastop].op.scale.d[1] = yyvsp[-2].val;
  op[lastop].op.scale.d[2] = yyvsp[-1].val;
  op[lastop].op.scale.d[3] = 0;
  op[lastop].op.scale.p = add_symbol(yyvsp[0].string,SYM_VALUE,0);
  lastop++;
;
    break;}
case 35:
#line 534 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SCALE;
  op[lastop].op.scale.d[0] = yyvsp[-2].val;
  op[lastop].op.scale.d[1] = yyvsp[-1].val;
  op[lastop].op.scale.d[2] = yyvsp[0].val;
  op[lastop].op.scale.d[3] = 0;
  op[lastop].op.scale.p = NULL;
  lastop++;
;
    break;}
case 36:
#line 545 "mdl.y"
{
  lineno++;
  op[lastop].opcode = ROTATE;
  switch (*yyvsp[-2].string)
    {
    case 'x':
    case 'X': 
      op[lastop].op.rotate.axis = 0;
      break;
    case 'y':
    case 'Y': 
      op[lastop].op.rotate.axis = 1;
      break;
    case 'z':
    case 'Z': 
      op[lastop].op.rotate.axis = 2;
      break;
    }

  op[lastop].op.rotate.degrees = yyvsp[-1].val;
  op[lastop].op.rotate.p = add_symbol(yyvsp[0].string,SYM_VALUE,0);
  
  lastop++;
;
    break;}
case 37:
#line 570 "mdl.y"
{
  lineno++;
  op[lastop].opcode = ROTATE;
  switch (*yyvsp[-1].string)
    {
    case 'x':
    case 'X': 
      op[lastop].op.rotate.axis = 0;
      break;
    case 'y':
    case 'Y': 
      op[lastop].op.rotate.axis = 1;
      break;
    case 'z':
    case 'Z': 
      op[lastop].op.rotate.axis = 2;
      break;
    }
  op[lastop].op.rotate.degrees = yyvsp[0].val;
  op[lastop].op.rotate.p = NULL;
  lastop++;
;
    break;}
case 38:
#line 593 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BASENAME;
  op[lastop].op.basename.p = add_symbol(yyvsp[0].string,SYM_STRING,0);
  lastop++;
;
    break;}
case 39:
#line 600 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SAVE_KNOBS;
  op[lastop].op.save_knobs.p = add_symbol(yyvsp[0].string,SYM_STRING,0);
  lastop++;
;
    break;}
case 40:
#line 607 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TWEEN;
  op[lastop].op.tween.start_frame = yyvsp[-3].val;
  op[lastop].op.tween.end_frame = yyvsp[-2].val;
  op[lastop].op.tween.knob_list0 = add_symbol(yyvsp[-1].string,SYM_STRING,0);
  op[lastop].op.tween.knob_list1 = add_symbol(yyvsp[0].string,SYM_STRING,0);
  lastop++;
;
    break;}
case 41:
#line 617 "mdl.y"
{
  lineno++;
  op[lastop].opcode = FRAMES;
  op[lastop].op.frames.num_frames = yyvsp[0].val;
  lastop++;
;
    break;}
case 42:
#line 624 "mdl.y"
{
  lineno++;
  op[lastop].opcode = VARY;
  op[lastop].op.vary.p = add_symbol(yyvsp[-4].string,SYM_STRING,0);
  op[lastop].op.vary.start_frame = yyvsp[-3].val;
  op[lastop].op.vary.end_frame = yyvsp[-2].val;
  op[lastop].op.vary.start_val = yyvsp[-1].val;
  op[lastop].op.vary.end_val = yyvsp[0].val;
  lastop++;
;
    break;}
case 43:
#line 635 "mdl.y"
{
  lineno++;
  op[lastop].opcode = PUSH;
  lastop++;
;
    break;}
case 44:
#line 641 "mdl.y"
{
  lineno++;
  op[lastop].opcode = GENERATE_RAYFILES;
  lastop++;
;
    break;}
case 45:
#line 647 "mdl.y"
{
  lineno++;
  op[lastop].opcode = POP;
  lastop++;
;
    break;}
case 46:
#line 653 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SAVE;
  op[lastop].op.save.p = add_symbol(yyvsp[0].string,SYM_FILE,0);
  lastop++;
;
    break;}
case 47:
#line 660 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SHADING;
  op[lastop].op.shading.p = add_symbol(yyvsp[0].string,SYM_STRING,0);
  lastop++;
;
    break;}
case 48:
#line 667 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SETKNOBS;
  op[lastop].op.setknobs.value = yyvsp[0].val;
  lastop++;
;
    break;}
case 49:
#line 674 "mdl.y"
{
  lineno++;
  op[lastop].opcode = FOCAL;
  op[lastop].op.focal.value = yyvsp[0].val;
  lastop++;
;
    break;}
case 50:
#line 681 "mdl.y"
{
  lineno++;
  op[lastop].opcode = DISPLAY;
  lastop++;
;
    break;}
}

#line 705 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 691 "mdl.y"


/* Other C stuff */



int yyerror(char *s)
{
  printf("Error in line %d:%s\n",lineno,s);
  return 0;
}

int yywrap()
{
  return 1;
}


extern FILE *yyin;

int main(int argc, char **argv)
{
    if (argc > 1)
    {
    yyin = fopen(argv[1],"r");
    }
  
  yyparse();
  print_symtab();
  print_pcode();
}
