-- start_ignore
SET gp_create_table_random_default_distribution=off;
-- end_ignore
-- start_ignore
drop table if exists subtx2_commit_t1;
-- end_ignore
create table subtx2_commit_t1(a1 int,a2 text) distributed randomly;
begin;
savepoint sp1; 
insert into subtx2_commit_t1 values(generate_series(1,10), 'sub-transactions with sub-commits and rollbacks');
 release sp1; 
savepoint sp2;
insert into subtx2_commit_t1 values(generate_series(1,10), 'sub-transactions with sub-commits and rollbacks');
rollback to sp2;
commit;

select count(*) from subtx2_commit_t1;
