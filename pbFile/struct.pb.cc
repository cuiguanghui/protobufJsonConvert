// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: struct.proto

#include "struct.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

class SearchRequestDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SearchRequest>
      _instance;
} _SearchRequest_default_instance_;
namespace protobuf_struct_2eproto {
static void InitDefaultsSearchRequest() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_SearchRequest_default_instance_;
    new (ptr) ::SearchRequest();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::SearchRequest::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_SearchRequest =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsSearchRequest}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_SearchRequest.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SearchRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SearchRequest, query_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SearchRequest, page_number_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SearchRequest, result_per_page_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::SearchRequest)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_SearchRequest_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "struct.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\014struct.proto\"L\n\rSearchRequest\022\r\n\005query"
      "\030\001 \001(\t\022\023\n\013page_number\030\002 \001(\005\022\027\n\017result_pe"
      "r_page\030\003 \001(\005b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 100);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "struct.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_struct_2eproto

// ===================================================================

void SearchRequest::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SearchRequest::kQueryFieldNumber;
const int SearchRequest::kPageNumberFieldNumber;
const int SearchRequest::kResultPerPageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SearchRequest::SearchRequest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_struct_2eproto::scc_info_SearchRequest.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:SearchRequest)
}
SearchRequest::SearchRequest(const SearchRequest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  query_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.query().size() > 0) {
    query_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.query_);
  }
  ::memcpy(&page_number_, &from.page_number_,
    static_cast<size_t>(reinterpret_cast<char*>(&result_per_page_) -
    reinterpret_cast<char*>(&page_number_)) + sizeof(result_per_page_));
  // @@protoc_insertion_point(copy_constructor:SearchRequest)
}

void SearchRequest::SharedCtor() {
  query_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&page_number_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&result_per_page_) -
      reinterpret_cast<char*>(&page_number_)) + sizeof(result_per_page_));
}

SearchRequest::~SearchRequest() {
  // @@protoc_insertion_point(destructor:SearchRequest)
  SharedDtor();
}

void SearchRequest::SharedDtor() {
  query_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void SearchRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* SearchRequest::descriptor() {
  ::protobuf_struct_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_struct_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SearchRequest& SearchRequest::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_struct_2eproto::scc_info_SearchRequest.base);
  return *internal_default_instance();
}


void SearchRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:SearchRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  query_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&page_number_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&result_per_page_) -
      reinterpret_cast<char*>(&page_number_)) + sizeof(result_per_page_));
  _internal_metadata_.Clear();
}

bool SearchRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SearchRequest)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string query = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_query()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->query().data(), static_cast<int>(this->query().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SearchRequest.query"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 page_number = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &page_number_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 result_per_page = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &result_per_page_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SearchRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SearchRequest)
  return false;
#undef DO_
}

void SearchRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SearchRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string query = 1;
  if (this->query().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->query().data(), static_cast<int>(this->query().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SearchRequest.query");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->query(), output);
  }

  // int32 page_number = 2;
  if (this->page_number() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->page_number(), output);
  }

  // int32 result_per_page = 3;
  if (this->result_per_page() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->result_per_page(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:SearchRequest)
}

::google::protobuf::uint8* SearchRequest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:SearchRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string query = 1;
  if (this->query().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->query().data(), static_cast<int>(this->query().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SearchRequest.query");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->query(), target);
  }

  // int32 page_number = 2;
  if (this->page_number() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->page_number(), target);
  }

  // int32 result_per_page = 3;
  if (this->result_per_page() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->result_per_page(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SearchRequest)
  return target;
}

size_t SearchRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SearchRequest)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string query = 1;
  if (this->query().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->query());
  }

  // int32 page_number = 2;
  if (this->page_number() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->page_number());
  }

  // int32 result_per_page = 3;
  if (this->result_per_page() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->result_per_page());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SearchRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SearchRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const SearchRequest* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SearchRequest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SearchRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SearchRequest)
    MergeFrom(*source);
  }
}

void SearchRequest::MergeFrom(const SearchRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SearchRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.query().size() > 0) {

    query_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.query_);
  }
  if (from.page_number() != 0) {
    set_page_number(from.page_number());
  }
  if (from.result_per_page() != 0) {
    set_result_per_page(from.result_per_page());
  }
}

void SearchRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SearchRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SearchRequest::CopyFrom(const SearchRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SearchRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SearchRequest::IsInitialized() const {
  return true;
}

void SearchRequest::Swap(SearchRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SearchRequest::InternalSwap(SearchRequest* other) {
  using std::swap;
  query_.Swap(&other->query_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(page_number_, other->page_number_);
  swap(result_per_page_, other->result_per_page_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata SearchRequest::GetMetadata() const {
  protobuf_struct_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_struct_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::SearchRequest* Arena::CreateMaybeMessage< ::SearchRequest >(Arena* arena) {
  return Arena::CreateInternal< ::SearchRequest >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
