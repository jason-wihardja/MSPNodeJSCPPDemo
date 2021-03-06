#include <node.h>
#include <string>

using namespace std;
using namespace v8;

void SayHello(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	if (args.Length() > 1) {
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Too many arguments")));
		return;
	} else if (args.Length() == 0) {
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World"));
	} else {
		if (!args[0]->IsString()) {
			isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments type")));
		} else {
			string argument(*String::Utf8Value(args[0]->ToString()));
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, argument.c_str()));
		}
	}
}

void Init(Handle<Object> exports) {
	NODE_SET_METHOD(exports, "hello", SayHello);
}

NODE_MODULE(HelloAddon, Init)