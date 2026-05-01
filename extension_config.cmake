# This file is included by DuckDB's build system. It specifies which extension to load

################# HTTPFS
duckdb_extension_load(json)
duckdb_extension_load(parquet)

duckdb_extension_load(httpfs
	SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}
	INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/src/include
)

duckdb_extension_load(aws
	GIT_URL https://github.com/duckdb/duckdb-aws
	GIT_TAG b2649e68341a9ee717588dd23f277904727ce793
)

duckdb_extension_load(avro
	GIT_URL https://github.com/duckdb/duckdb-avro
	GIT_TAG a73b60d629a92146cfd71c210936144a971783bd
)

duckdb_extension_load(iceberg
	GIT_URL https://github.com/duckdb/duckdb-iceberg
	GIT_TAG 11fea8ed1d405c4cb69511d13b85d600dcdb44c4
)
