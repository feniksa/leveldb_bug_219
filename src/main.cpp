#include <iostream>
#include <assert.h>
#include <string>
#include <leveldb/db.h>
#include <exception>

using namespace std;

void spamDatabase(leveldb::DB* db) 
{
	leveldb::Status status;
	leveldb::WriteOptions writeOptions;	
	
	leveldb::Slice value { "1234" };
	
	for (size_t i = 0; ; ++i) {
		status = db->Put(writeOptions, to_string(i), value);
		if ( !status.ok() ) {
			cerr << "Error writing: " <<  status.ToString() << endl;
			throw std::exception();
		}	
		
		cout << "writen: " << i * sizeof(char) * value.size() << endl;
	}
}

int main(int argc, const char** argv) 
{
	if (argc != 2) {
		cerr << "Not enought params. Usage: leveldb [dbpath]" << endl;
		return -1;
	}
	
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, argv[1], &db);
	assert(status.ok());
	
	try {
		spamDatabase(db);
	} catch (const std::exception& e) {
		
		cout << "Catch exception" << endl;
		
		return 0;
	}
	
	/*leveldb::ReadOptions readOptions;
	
	string value;
	status = db->Get(readOptions, leveldb::Slice("key"), &value);
	if ( !status.ok() ) {
		cerr << "Error reading: " <<  status.ToString() << endl;
		delete db;
		return -3;
	}
	
	cout << value << endl;
	delete db;*/
	
	return 0;
}
