/*-------------------------------------------------------------------------
 *
 * parse_utilcmd.h
 *		parse analysis for utility commands
 *
 *
 * Portions Copyright (c) 1996-2009, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/parser/parse_utilcmd.h,v 1.4 2009/01/01 17:24:00 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef PARSE_UTILCMD_H
#define PARSE_UTILCMD_H

#include "nodes/parsenodes.h"
#include "parser/analyze.h"
#include "parser/parse_node.h"


extern List *transformCreateStmt(CreateStmt *stmt, const char *queryString, bool createPartition);
extern List *transformCreateExternalStmt(CreateExternalStmt *stmt, const char *queryString);
extern List *transformAlterTableStmt(AlterTableStmt *stmt,
						const char *queryString);
extern List *transformIndexStmt(IndexStmt *stmt, const char *queryString);
extern void transformRuleStmt(RuleStmt *stmt, const char *queryString,
				  List **actions, Node **whereClause);
extern List *transformCreateSchemaStmt(CreateSchemaStmt *stmt);

extern void transformInhRelation(ParseState *pstate, CreateStmtContext *cxt,
								 InhRelation *inhRelation, bool forceBareCol);

#endif   /* PARSE_UTILCMD_H */
