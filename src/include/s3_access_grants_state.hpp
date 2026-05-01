#pragma once

#include "lru_cache.hpp"
#include "duckdb/common/file_opener.hpp"
#include "duckdb/main/client_context.hpp"
#include "duckdb/main/client_context_state.hpp"
#include "duckdb/common/types/timestamp.hpp"

namespace duckdb {

struct TemporaryAWSCredential {
	string access_key_id;
	string secret_access_key;
	string session_token;
	timestamp_t expiration {};
};

class S3AccessGrantsState : public ClientContextState {
public:
	S3AccessGrantsState()
	    : account_id_cache(1024), bucket_owner_account_id_cache(2048), access_grants_cache(4096),
	      access_denied_cache(4096) {
	}

	LRUCache<string, string> account_id_cache;
	LRUCache<string, string> bucket_owner_account_id_cache;
	LRUCache<string, TemporaryAWSCredential> access_grants_cache;
	LRUCache<string, timestamp_t> access_denied_cache;

	static shared_ptr<S3AccessGrantsState> TryGetState(ClientContext &context);
	static shared_ptr<S3AccessGrantsState> TryGetState(optional_ptr<FileOpener> opener);
};

} // namespace duckdb
