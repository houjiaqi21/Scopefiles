#pragma warning( disable : 4100 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4355 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4512 )
#pragma warning( disable:  4651 )
#pragma warning( disable : 4691 )
#pragma warning( disable : 4723 )
#pragma warning( disable : 4702 )
#define SCOPE_NO_UDT
#if defined(COMPILE_NATIVE)
#include "ScopeCommonError.h"
#include "ScopeError.h"
#include "ScopeOperators.h"
#endif
#if defined(COMPILE_MANAGED)
#using <mscorlib.dll>
[assembly: System::Runtime::Versioning::TargetFrameworkAttribute(".NETFramework,Version=v4.7.2", FrameworkDisplayName = ".NET Framework, Version 4.7.2")];
#include "ScopeManaged.h"
#include "StreamingUtils.h"
#endif
#if defined(COMPILE_NATIVE)
#endif
using namespace ScopeEngine;

static ScopeEngine::CompilerSettings GetCompilerSettings()
{
    static ScopeEngine::CompilerSettings settings;
    settings.m_enableWriteBehindCacheService = false;
    settings.m_allowUserDataInException = true;
    settings.m_restrictOperatorMemorySpilling = false;
    settings.m_storeType = ScopeEngine::StoreType::LocalStore;
    settings.m_verboseRuntimeStatistic = false;
    settings.m_vertexClassifyStoreError = true;
    return settings;
};
enum OperatorUID
{
UID_Extract_0 = 1,
    UID_Extract_0_Data0 = 2,
    UID_Split_1 = 3,
    UID_SV1_Extract_Split_out0 = 4,
    UID_SV1_Extract_Split_out1 = 5,
    UID_Output_2 = 6,
    UID_Process_3 = 7,
    UID_SV2_Process_out0 = 8,
    UID_Extract_4 = 9,
    UID_Extract_4_Data0 = 10,
    UID_Split_5 = 11,
    UID_SV3_Extract_Split_out0 = 12,
    UID_SV3_Extract_Split_out1 = 13,
    UID_SV3_Extract_Split_out2 = 14,
    UID_SV3_Extract_Split_out3 = 15,
    UID_SV3_Extract_Split_out4 = 16,
    UID_Process_6 = 17,
    UID_SV4_Process_out0 = 18,
    UID_Join_7 = 19,
    UID_Join_7_Data0 = 20,
    UID_SV5_Combine_out0 = 21,
    UID_Output_9 = 22,
    UID_Process_10 = 23,
    UID_Process_10_Data0 = 24,
    UID_Process_11 = 25,
    UID_Process_11_Data0 = 26,
    UID_SV6_Process_out0 = 27,
    UID_Process_13 = 28,
    UID_Process_13_Data0 = 29,
    UID_Process_14 = 30,
    UID_Process_14_Data0 = 31,
    UID_Process_15 = 32,
    UID_Process_15_Data0 = 33,
    UID_SV7_Process_out0 = 34,
    UID_Output_17 = 35,
    UID_Split_1_0,
    UID_Split_1_1,
    UID_Split_5_0,
    UID_Split_5_1,
    UID_Split_5_2,
    UID_Split_5_3,
    UID_Split_5_4,
    UID_Join_7_0,
    UID_Join_7_1,
    UID_Process_3_Prefix,
    UID_Process_6_Prefix,
    UID_Process_13_Prefix,
    UID_ParallelUnionAll_Extract_0,
    UID_ParallelUnionAll_Extract_4
};

//namespace ScopeGeneratedClasses
//{
    // IDs representing UDTs to be used in native code
    enum UserDefinedTypeId
    {
        
    };

#if defined(COMPILE_MANAGED)
// Explicit instantiations for templated functions that are defined in managed code
#endif // defined(COMPILE_MANAGED)


    class Extract_0_Data0
    {
    public:
        int m_AdId;
        int m_IId;
        int m_Impression;
        int m_IsClicked;

        Extract_0_Data0();
        Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Extract_0_Data0(const Extract_0_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Extract_0_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"AdId:int,IId:int,Impression:int,IsClicked:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_0_Data0) == 16, "Incorrect size of row schema");

    class SV1_Extract_Split_out1
    {
    public:
        int m_AdId;
        int m_IId;
        int m_Impression;

        SV1_Extract_Split_out1();
        SV1_Extract_Split_out1(const SV1_Extract_Split_out1 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        SV1_Extract_Split_out1(const SV1_Extract_Split_out1 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const SV1_Extract_Split_out1& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"AdId:int,IId:int,Impression:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(SV1_Extract_Split_out1) == 12, "Incorrect size of row schema");

    class Extract_4_Data0
    {
    public:
        int m_IId;
        int m_UId;
        ScopeDateTime m_Start;
        FString m_Market;
        FString m_Query;
        int m_DwellTime;
        FString m_Results;
        FString m_ClickedUrls;

        Extract_4_Data0();
        Extract_4_Data0(const Extract_4_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Extract_4_Data0(const Extract_4_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Extract_4_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"IId:int,UId:int,Start:DateTime,Market:string,Query:string,DwellTime:int,Results:string,ClickedUrls:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_4_Data0) == 88, "Incorrect size of row schema");

    class SV3_Extract_Split_out0
    {
    public:
        FString m_Query;
        int m_IId1;

        SV3_Extract_Split_out0();
        SV3_Extract_Split_out0(const SV3_Extract_Split_out0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        SV3_Extract_Split_out0(const SV3_Extract_Split_out0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const SV3_Extract_Split_out0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Query:string,IId1:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(SV3_Extract_Split_out0) == 24, "Incorrect size of row schema");

    class SV3_Extract_Split_out2
    {
    public:
        FString m_Market;
        FString m_Results;

        SV3_Extract_Split_out2();
        SV3_Extract_Split_out2(const SV3_Extract_Split_out2 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        SV3_Extract_Split_out2(const SV3_Extract_Split_out2 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const SV3_Extract_Split_out2& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Market:string,Results:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(SV3_Extract_Split_out2) == 32, "Incorrect size of row schema");

    class SV3_Extract_Split_out3
    {
    public:
        FString m_Market;
        double m_DwellTimeDouble;

        SV3_Extract_Split_out3();
        SV3_Extract_Split_out3(const SV3_Extract_Split_out3 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        SV3_Extract_Split_out3(const SV3_Extract_Split_out3 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const SV3_Extract_Split_out3& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Market:string,DwellTimeDouble:double" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(SV3_Extract_Split_out3) == 24, "Incorrect size of row schema");

    class SV3_Extract_Split_out4
    {
    public:
        int m_IId;
        int m_UId;
        ScopeDateTime m_Start;
        FString m_Market;
        FString m_Query;
        int m_DwellTime;
        FString m_Results;
        FString m_ClickedUrlsCount;

        SV3_Extract_Split_out4();
        SV3_Extract_Split_out4(const SV3_Extract_Split_out4 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        SV3_Extract_Split_out4(const SV3_Extract_Split_out4 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const SV3_Extract_Split_out4& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"IId:int,UId:int,Start:DateTime,Market:string,Query:string,DwellTime:int,Results:string,ClickedUrlsCount:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(SV3_Extract_Split_out4) == 88, "Incorrect size of row schema");

    class Join_7_Data0
    {
    public:
        int m_AdId;
        int m_IId;
        int m_Impression;
        FString m_Query;

        Join_7_Data0();
        Join_7_Data0(const Join_7_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Join_7_Data0(const Join_7_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Join_7_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"AdId:int,IId:int,Impression:int,Query:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Join_7_Data0) == 32, "Incorrect size of row schema");

    class Process_10_Data0
    {
    public:
        FString m_Market;
        FString m_SplitResult;

        Process_10_Data0();
        Process_10_Data0(const Process_10_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Process_10_Data0(const Process_10_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Process_10_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Market:string,SplitResult:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_10_Data0) == 32, "Incorrect size of row schema");

    class Process_11_Data0
    {
    public:
        FString m_Market;
        FString m_Result;

        Process_11_Data0();
        Process_11_Data0(const Process_11_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Process_11_Data0(const Process_11_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Process_11_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Market:string,Result:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_11_Data0) == 32, "Incorrect size of row schema");

    class Process_14_Data0
    {
    public:
        FString m_Market;
        double m_TotalDwellTime;

        Process_14_Data0();
        Process_14_Data0(const Process_14_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Process_14_Data0(const Process_14_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Process_14_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Market:string,TotalDwellTime:double" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_14_Data0) == 24, "Incorrect size of row schema");

#if defined(COMPILE_MANAGED)
    template<>
    struct ManagedRow<Extract_0_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_AdId_Integer_IId_Integer_Impression_Integer_IsClicked_Integer Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };
    template<>
    struct ManagedRow<Extract_4_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_2BFC241179AB532 Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };
    template<>
    struct ManagedRow<SV3_Extract_Split_out0>
    {
        typedef ___Scope_Generated_Classes___::Row_Query_String_IId1_Integer Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };
    template<>
    struct ManagedRow<SV3_Extract_Split_out2>
    {
        typedef ___Scope_Generated_Classes___::Row_Market_String_Results_String Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };
    template<>
    struct ManagedRow<SV3_Extract_Split_out3>
    {
        typedef ___Scope_Generated_Classes___::Row_Market_String_DwellTimeDouble_Double Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };
    template<>
    struct ManagedRow<SV3_Extract_Split_out4>
    {
        typedef ___Scope_Generated_Classes___::Row_2EDD8A91968976D1 Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };
    template<>
    struct ManagedRow<Process_10_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_Market_String_SplitResult_String Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };
    template<>
    struct ManagedRow<Process_14_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_Market_String_TotalDwellTime_Double Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };

#endif // defined(COMPILE_MANAGED)





#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<SV1_Extract_Split_out1>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, SV1_Extract_Split_out1 & row)
        {
            try
            {
                input->Read(row.m_AdId);
                input->Read(row.m_IId);
                input->Read(row.m_Impression);
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<SV1_Extract_Split_out1>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, SV1_Extract_Split_out1 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            output->Write(row.m_AdId);
            output->Write(row.m_IId);
            output->Write(row.m_Impression);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const SV1_Extract_Split_out1 & row)
        {
            SCOPE_ASSERT(false); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const SV1_Extract_Split_out1 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<SV3_Extract_Split_out0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, SV3_Extract_Split_out0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Query);
                    input->Read(row.m_IId1);
                }
                else
                {
                    char ___masking___[1];
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Query);
                    }
                    else
                    {
                        row.m_Query.SetNull();
                    }
                    input->Read(row.m_IId1);
                }
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<SV3_Extract_Split_out0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, SV3_Extract_Split_out0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Query.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            if (!row.m_Query.IsNull())
            {
                output->Write(row.m_Query);
            }
            output->Write(row.m_IId1);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const SV3_Extract_Split_out0 & row)
        {
            SCOPE_ASSERT(false); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const SV3_Extract_Split_out0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<SV3_Extract_Split_out2>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, SV3_Extract_Split_out2 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Market);
                    input->Read(row.m_Results);
                }
                else
                {
                    char ___masking___[1];
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Market);
                    }
                    else
                    {
                        row.m_Market.SetNull();
                    }
                    if ((___masking___[0] & 4 ) != 4)
                    {
                        input->Read(row.m_Results);
                    }
                    else
                    {
                        row.m_Results.SetNull();
                    }
                }
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<SV3_Extract_Split_out2>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, SV3_Extract_Split_out2 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Market.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (row.m_Results.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 4;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            if (!row.m_Market.IsNull())
            {
                output->Write(row.m_Market);
            }
            if (!row.m_Results.IsNull())
            {
                output->Write(row.m_Results);
            }
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const SV3_Extract_Split_out2 & row)
        {
            SCOPE_ASSERT(false); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const SV3_Extract_Split_out2 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<SV3_Extract_Split_out3>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, SV3_Extract_Split_out3 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Market);
                    input->Read(row.m_DwellTimeDouble);
                }
                else
                {
                    char ___masking___[1];
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Market);
                    }
                    else
                    {
                        row.m_Market.SetNull();
                    }
                    input->Read(row.m_DwellTimeDouble);
                }
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<SV3_Extract_Split_out3>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, SV3_Extract_Split_out3 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Market.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            if (!row.m_Market.IsNull())
            {
                output->Write(row.m_Market);
            }
            output->Write(row.m_DwellTimeDouble);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const SV3_Extract_Split_out3 & row)
        {
            SCOPE_ASSERT(false); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const SV3_Extract_Split_out3 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };

#pragma region Schema Constructors


    INLINE Extract_0_Data0::Extract_0_Data0()
    {
        m_AdId = 0;
        m_IId = 0;
        m_Impression = 0;
        m_IsClicked = 0;
    }
    INLINE Extract_0_Data0::Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc)
    {
        m_AdId = c.m_AdId;
        m_IId = c.m_IId;
        m_Impression = c.m_Impression;
        m_IsClicked = c.m_IsClicked;
    }



    INLINE SV1_Extract_Split_out1::SV1_Extract_Split_out1()
    {
        m_AdId = 0;
        m_IId = 0;
        m_Impression = 0;
    }
    INLINE SV1_Extract_Split_out1::SV1_Extract_Split_out1(const SV1_Extract_Split_out1 & c, IncrementalAllocator * alloc)
    {
        m_AdId = c.m_AdId;
        m_IId = c.m_IId;
        m_Impression = c.m_Impression;
    }



    INLINE Extract_4_Data0::Extract_4_Data0()
    {
        m_IId = 0;
        m_UId = 0;
        m_DwellTime = 0;
    }
    INLINE Extract_4_Data0::Extract_4_Data0(const Extract_4_Data0 & c, IncrementalAllocator * alloc) :
            m_Start(c.m_Start),
            m_Market(c.m_Market, alloc),
            m_Query(c.m_Query, alloc),
            m_Results(c.m_Results, alloc),
            m_ClickedUrls(c.m_ClickedUrls, alloc)
    {
        m_IId = c.m_IId;
        m_UId = c.m_UId;
        m_DwellTime = c.m_DwellTime;
    }



    INLINE SV3_Extract_Split_out0::SV3_Extract_Split_out0()
    {
        m_IId1 = 0;
    }
    INLINE SV3_Extract_Split_out0::SV3_Extract_Split_out0(const SV3_Extract_Split_out0 & c, IncrementalAllocator * alloc) :
            m_Query(c.m_Query, alloc)
    {
        m_IId1 = c.m_IId1;
    }



    INLINE SV3_Extract_Split_out2::SV3_Extract_Split_out2()
    {
    }



    INLINE SV3_Extract_Split_out3::SV3_Extract_Split_out3()
    {
        m_DwellTimeDouble = 0.0;
    }
    INLINE SV3_Extract_Split_out3::SV3_Extract_Split_out3(const SV3_Extract_Split_out3 & c, IncrementalAllocator * alloc) :
            m_Market(c.m_Market, alloc)
    {
        m_DwellTimeDouble = c.m_DwellTimeDouble;
    }



    INLINE SV3_Extract_Split_out4::SV3_Extract_Split_out4()
    {
        m_IId = 0;
        m_UId = 0;
        m_DwellTime = 0;
    }



    INLINE Join_7_Data0::Join_7_Data0()
    {
        m_AdId = 0;
        m_IId = 0;
        m_Impression = 0;
    }



    INLINE Process_10_Data0::Process_10_Data0()
    {
    }



    INLINE Process_11_Data0::Process_11_Data0()
    {
    }



    INLINE Process_14_Data0::Process_14_Data0()
    {
        m_TotalDwellTime = 0.0;
    }

#pragma endregion Schema Constructors
#pragma hdrstop


#if defined(COMPILE_INIT_SHUTDOWN)
#if defined(COMPILE_MANAGED)
extern "C" __declspec(dllexport) void __stdcall InitVertexManaged(std::string * argv, int argc)
{
#if defined(FORCEMANAGEDDATETIMESER)
    ScopeEngine::ScopeDateTime::ForceManagedSerialization = true;
#endif
    cli::array<String^>^ arguments = ScopeEngineManaged::GroupArguments(argv, argc);
    ScopeEngineManaged::InitializeScopeEngineManaged(arguments);

    // Register Debug Streams from command line arguments
    ScopeRuntime::Global::DebugStreamManager->RegisterDebugStreams(arguments);
    auto traceListener = gcnew System::Diagnostics::ConsoleTraceListener();
    traceListener->TraceOutputOptions = System::Diagnostics::TraceOptions::DateTime | System::Diagnostics::TraceOptions::ProcessId | System::Diagnostics::TraceOptions::ThreadId;
    ScopeRuntime::ScopeTrace::AddListener(traceListener);

    ScopeRuntime::RuntimeConfiguration::Initialize(___Scope_Generated_Classes___::__UdtTypeTable__);
}

extern "C" __declspec(dllexport) void __stdcall ShutdownVertexManaged(CLRMemoryStat& stat)
{
    ScopeEngineManaged::FinalizeScopeEngineManaged(stat);
    ScopeRuntime::ScopeTrace::RemoveAllListeners();
    ScopeRuntime::Global::DebugStreamManager->FinalizeDebugStreams();
}

// < 0 indicates that server GC config will be determined at vertex startup.
// = 0 indicates that default server GC should be used, with one affinitized blocking-GC thread per core.
// > 0 specifies number of heaps/blocking threads, but with core-affinity disabled.
extern "C" __declspec(dllexport) const int UnaffinitizedServerGcHeaps { -1 };
#endif //#if defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)


extern "C" __declspec(dllexport) void __stdcall InitVertexNative(VertexExecutionInfo * vertexExecutionInfo)
{
#if defined(FORCEMANAGEDDATETIMESER)
    ScopeEngine::ScopeDateTime::ForceManagedSerialization = true;
#endif

    ErrorManager::GetGlobal()->EnableJSON();
    ErrorManager::GetGlobal()->EnableRowDump();
}

// Add broadcast vertex code
extern "C" __declspec(dllexport) void __stdcall SV_CopyThrough_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
{
    ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
    SCOPE_ASSERT(inputCnt == 1 && outputCnt == 1);
    IOManager::CopyStream(IOManager::GetGlobal()->GetDevice(inputs[0].inputFileName), IOManager::GetGlobal()->GetDevice(outputs[0].outputFileName));
}
#endif //#if defined(COMPILE_NATIVE)


#endif //#if defined(COMPILE_INIT_SHUTDOWN)
#pragma region SV1_Extract_Split
#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_MANAGED)
    template<>
    struct ManagedUDO<UID_Extract_0>
    {
        typedef ScopeRuntime::Extractor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Extract_0());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{})));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Extract_0, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_AdId_Integer_IId_Integer_Impression_Integer_IsClicked_Integer();
            m_udo->GetType()->GetField("_outputRow", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), curRow);
            m_udo->GetType()->GetField("_outputSchema", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), m_udo->DefaultRow->Schema);
            m_udo->GetType()->GetField("_args", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), m_args->ToArray());
        }

        static constexpr int StreamIdColumnIndex()
        {
            return -1;
        }

        UDO^ get()
        {
            return m_udo.get();
        }

        Generic::List<String^>^ args()
        {
            return m_args.get();
        }
        cli::array<String^>^ ReadOnlyColumns_Output()
        {
            return nullptr;
        }

        cli::array<String^>^ ReadOnlyColumns_Input()
        {
            return nullptr;
        }

    private:
        ScopeTypedManagedHandle<UDO^> m_udo;
        ScopeTypedManagedHandle<Generic::List<String^>^> m_args;
        ManagedUDO & operator=(ManagedUDO &);
    };
    template<>
    class InteropToNativeRowSystemColumnPolicy<Extract_0_Data0, UID_Extract_0>
    {
    public:
        static void SetStreamIdSystemColumn(int streamId, Extract_0_Data0& nativeRow)
        {
            SCOPE_ASSERT(!"SetStreamIdSystemColumn method should not be invoked.");
        }
    };
    template<>
    class InteropToNativeRowPolicy<Extract_0_Data0, UID_Extract_0>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Extract_0_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_AdId, managedRow[0]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_IId, managedRow[1]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Impression, managedRow[2]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_IsClicked, managedRow[3]->Integer, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Extract_0_Data0, UID_Output_2>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_0_Data0 & row)
        {
            output->Write<int,false>(row.m_AdId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_IId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Impression);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_IsClicked);
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

    static const char * StringTable_Split_1_0 [] =
    {
        "AdId",
        "IId",
        "Impression",
        "IsClicked",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_0_Data0, Extract_0_Data0, UID_Split_1_0>
    {
    public:
        void Init(ManagedRow<Extract_0_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_0_Data0 & input, Extract_0_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                    output.m_AdId = input.m_AdId;
                    exceptionIndex++;
                    output.m_IId = input.m_IId;
                    exceptionIndex++;
                    output.m_Impression = input.m_Impression;
                    exceptionIndex++;
                    output.m_IsClicked = input.m_IsClicked;
                    exceptionIndex++;
                    return true;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_1_0[exceptionIndex]));
            }
            }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Split_1_1 [] =
    {
        "AdId",
        "IId",
        "Impression",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_0_Data0, SV1_Extract_Split_out1, UID_Split_1_1>
    {
    public:
        void Init(ManagedRow<Extract_0_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_0_Data0 & input, SV1_Extract_Split_out1 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                    output.m_AdId = input.m_AdId;
                    exceptionIndex++;
                    output.m_IId = input.m_IId;
                    exceptionIndex++;
                    output.m_Impression = input.m_Impression;
                    exceptionIndex++;
                    return true;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_1_1[exceptionIndex]));
            }
            }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };






#if defined(COMPILE_NATIVE)
    template<> 
    class SplitPolicy<typename Extract_0_Data0, UID_Split_1>
    {
        SIZE_T m_outputBufSize;
        int m_outputBufCnt;

        typedef SplitOutputterSentinel<Extract_0_Data0> SplitOutputType_Split_1_2;
        SplitOutputType_Split_1_2 splitOutputter_Split_1_2;

        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<SV1_Extract_Split_out1, BinaryOutputStream, BinaryOutputPolicy<SV1_Extract_Split_out1>> OutputPolicyWrapperType_Split_1_1;

        typedef SplitOutputter<
            SplitOutputType_Split_1_2, 
            SV1_Extract_Split_out1, 
            OutputPolicyWrapperType_Split_1_1, 
            ExecutionStats, 
            UID_Split_1_1> 
            SplitOutputType_Split_1_1;

        SplitOutputType_Split_1_1 splitOutputter_Split_1_1;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<Extract_0_Data0, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, TextOutputPolicy<Extract_0_Data0, UID_Output_2>> OutputPolicyWrapperType_Split_1_0;

        typedef SplitOutputter<
            SplitOutputType_Split_1_1, 
            Extract_0_Data0, 
            OutputPolicyWrapperType_Split_1_0, 
            ExecutionStats, 
            UID_Split_1_0> 
            SplitOutputType_Split_1_0;

        SplitOutputType_Split_1_0 splitOutputter_Split_1_0;


    public:
        SplitPolicy(OutputFileInfo * outputFiles, SIZE_T outputBufSize, int outputBufCnt) : m_outputBufSize(outputBufSize), m_outputBufCnt(outputBufCnt),
            splitOutputter_Split_1_1(&splitOutputter_Split_1_2, new OutputPolicyWrapperType_Split_1_1(outputFiles[1].outputFileName, outputBufSize, outputBufCnt, false), outputFiles[1].outputFileName, false, UID_SV1_Extract_Split_out1),
            splitOutputter_Split_1_0(&splitOutputter_Split_1_1, new OutputPolicyWrapperType_Split_1_0(outputFiles[0].outputFileName, outputBufSize, outputBufCnt, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), false), outputFiles[0].outputFileName, false, UID_SV1_Extract_Split_out0)
        {
        }

        void SetSequenceNumber(int sequenceNumber)
        {
            splitOutputter_Split_1_1.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_1_0.SetSequenceNumber(sequenceNumber);
        }

        void Init()
        {
            
            splitOutputter_Split_1_0.Init(nullptr);
        }

        void BeginDataRead()
        {
            splitOutputter_Split_1_0.BeginDataRead();
        }

        void Close()
        {
            splitOutputter_Split_1_0.Close();
        }

        void ProcessMetadata(PartitionMetadata * metadata)
        {
            splitOutputter_Split_1_0.ProcessMetadata(metadata);
        }

        void OutputHeader()
        {
            splitOutputter_Split_1_0.OutputHeader();
        }

        void ProcessRow(Extract_0_Data0 & input)
        {
            splitOutputter_Split_1_0.ProcessRow(input);
        }

        __declspec(noinline)
        void WriteRuntimeStats(TreeNode & root) const
        {
            splitOutputter_Split_1_0.WriteRuntimeStats(root);
        }

        LONGLONG GetTotalIoWaitTime() const
        {
            return splitOutputter_Split_1_0.GetTotalIoWaitTime();
        }

        // get operator resource requirements
        ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return splitOutputter_Split_1_0.GetOperatorRequirements()
	.AddMemoryForOutputUStreams(1, m_outputBufSize, m_outputBufCnt)
	.AddMemoryForOutputUStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), m_outputBufCnt);
        }

        void FlushOutput(bool forcePersistent = false)
        {
            splitOutputter_Split_1_0.FlushOutput(forcePersistent);
        }

    };

#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV1_Extract_Split_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
            // move all empty inputs to the end of extractor array so we can always get metadata from the first input
            std::stable_partition(&inputs[0], inputs + inputCnt - 0, [](const InputFileInfo& input){ return input.length != 0; });
        }
        // Define extractor type and construct objects
        // 
        typedef ScopeExtractor<CosmosInput, Extract_0_Data0, -1> ExtractorType1_SV1_Extr_Split;
        unique_ptr<unique_ptr<ExtractorType1_SV1_Extr_Split>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV1_Extr_Split>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            // 
            extractor_0_array[i - 0].reset(new ExtractorType1_SV1_Extr_Split(ScopeExtractorManagedFactory::Make<CosmosInput,Extract_0_Data0,UID_Extract_0, 0>(argv, argc), inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_Extract_0));
        }

    ExtractorType1_SV1_Extr_Split ** extractor_0 = (ExtractorType1_SV1_Extr_Split **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;
        // Merge streams N->1
        typedef ParallelUnionAll<ExtractorType1_SV1_Extr_Split, Extract_0_Data0, IsNativeOnlyVertex> UnionAllType_Extract_0_Split_1_connector;
        unique_ptr<UnionAllType_Extract_0_Split_1_connector> unionall_Extract_0_Split_1_connector_ptr(new UnionAllType_Extract_0_Split_1_connector(extractor_0,extractor_0_count,12,419430400,UID_ParallelUnionAll_Extract_0));
        UnionAllType_Extract_0_Split_1_connector * unionall_Extract_0_Split_1_connector = unionall_Extract_0_Split_1_connector_ptr.get();
        ULONG unionall_Extract_0_Split_1_connector_count = 1;
        // Define splitter type

        typedef Splitter<UnionAllType_Extract_0_Split_1_connector, Extract_0_Data0, false, UID_Split_1> SplitterType_Split_1;

        // Construct operator and initialize it.
        unique_ptr<SplitterType_Split_1> splitter_Split_1_ptr (new SplitterType_Split_1(unionall_Extract_0_Split_1_connector, outputs, x_outputBufSize, x_outputBufCnt, UID_Split_1, false));
        SplitterType_Split_1 * splitter_Split_1 = splitter_Split_1_ptr.get();

        if (argv != nullptr && argc > 0)
        {
            try
            {
                int sequenceNumber = GetSequenceNumber(argv, argc);
                splitter_Split_1->SetSequenceNumber(sequenceNumber);
            }
            catch(const RuntimeException&)
            {
                // Sequence number will remain 0 in splitter_Split_1.
            }
        }

        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *splitter_Split_1) };

        try
        {
            // Init operator chain
            splitter_Split_1->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_0_Data0 row;
            splitter_Split_1->GetNextRow(row);

            // Close operator chain
            splitter_Split_1->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        splitter_Split_1->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
template ScopeExtractorManaged<CosmosInput,Extract_0_Data0> * ScopeEngine::ScopeExtractorManagedFactory::Make<CosmosInput, Extract_0_Data0, UID_Extract_0, 0>(std::string * argv, int argc);
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV1_Extract_Split
#pragma region SV2_Process
#if defined(COMPILE_SV2_PROCESS) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<SV1_Extract_Split_out1,UID_Process_3>
    {
    public:
        struct KeyStruct
        {
            int m_IId;

            KeyStruct(SV1_Extract_Split_out1 & c) :
                m_IId(c.m_IId)
            {
            }

            KeyStruct(const SV1_Extract_Split_out1 & c, IncrementalAllocator * alloc) :
                m_IId(const_cast<SV1_Extract_Split_out1&>(c).m_IId)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_IId(c.m_IId)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_IId(const_cast<KeyStruct&>(c).m_IId)
            {
            }

            KeyStruct() :
                m_IId(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"IId:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV1_Extract_Split_out1 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_IId, key.m_IId)) != 0)
                return r;
            return r;
        }

        static int Compare(SV1_Extract_Split_out1 * n1, SV1_Extract_Split_out1 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_IId, (*n2).m_IId)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(SV1_Extract_Split_out1 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_IId);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(SV1_Extract_Split_out1 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };




#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV2_Process_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // Define extractor type and construct object
        typedef Extractor<SV1_Extract_Split_out1, BinaryExtractPolicy<SV1_Extract_Split_out1>, BinaryInputStream> ExtractorType1_SV2_Proc;        
        unique_ptr<ExtractorType1_SV2_Proc> extractor_0_ptr= make_unique<ExtractorType1_SV2_Proc>(inputs[0], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV1_Extract_Split_out1);
        ExtractorType1_SV2_Proc * extractor_0 = extractor_0_ptr.get();
        ULONG extractor_0_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<SV1_Extract_Split_out1>> delegate_extractor_0_ptr (new OperatorDelegate<SV1_Extract_Split_out1>(OperatorDelegate<SV1_Extract_Split_out1>::FromOperator(extractor_0)));
        OperatorDelegate<SV1_Extract_Split_out1> * delegate_extractor_0 = delegate_extractor_0_ptr.get();
        ULONG delegate_extractor_0_count = 1;
        // Define sorter type
        typedef Sorter<SV1_Extract_Split_out1> SorterType_Process_3;
        // Construct operator and initialize it.
        unique_ptr<SorterType_Process_3> sorter_Process_3_ptr (new SorterType_Process_3(delegate_extractor_0, &StdSort<SV1_Extract_Split_out1>::Sort<KeyComparePolicy<SV1_Extract_Split_out1, UID_Process_3>, (sizeof(SV1_Extract_Split_out1)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<SV1_Extract_Split_out1>::CreateDelegate<UID_Process_3>(), false, 5859442676 /*memoryQuota*/, UID_Process_3));
        SorterType_Process_3 * sorter_Process_3 = sorter_Process_3_ptr.get();
        ULONG sorter_Process_3_count = 1;
        // Define outputter type
        typedef Outputter<SorterType_Process_3, SV1_Extract_Split_out1, BinaryOutputPolicy<SV1_Extract_Split_out1>, BinaryOutputStream, false> OutputterType2_SV2_Proc;
        // Construct operator and initialize it
        unique_ptr<OutputterType2_SV2_Proc> outputter_SV2_Process_out0_ptr(new OutputterType2_SV2_Proc(sorter_Process_3, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, UID_SV2_Process_out0, false));
        OutputterType2_SV2_Proc * outputter_SV2_Process_out0 = outputter_SV2_Process_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV2_Process_out0) };

        try
        {
            // Init operator chain
            outputter_SV2_Process_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            SV1_Extract_Split_out1 row;
            outputter_SV2_Process_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV2_Process_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV2_Process_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV2_Process
#pragma region SV3_Extract_Split
#if defined(COMPILE_SV3_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_NATIVE)
    template<> 
    class TextExtractPolicy<Extract_4_Data0, UID_Extract_4>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_4_Data0 & row)
        {
            for(;;)
            {
                try
                {
                    // When we start a new row we always skip all empty lines first.
                    if (!input->StartRow())
                    {
                        return false;
                    }

                    input->Read(row.m_IId);
                    input->Read(row.m_UId);
                    input->Read(row.m_Start);
                    input->Read(row.m_Market);
                    input->Read(row.m_Query);
                    input->Read(row.m_DwellTime);
                    input->Read(row.m_Results);
                    input->Read(row.m_ClickedUrls);

                    if (!input->EndRow())
                    {
                        // Too many columns in row - report error.
                        throw ScopeStreamExceptionWithEvidence(
                            E_EXTRACT_ROW_DELIMITER_EXPECTED,
                            { input->CurrentLineNumber(), input->CurrentField() },
                            EvidenceFormatter::FormatText(
                                input->GetBufferStart(),
                                input->GetReadPosition(),
                                input->GetBufferEnd(),
                                input->rowDelimiter,
                                input->delimiter));
                    }
                    return true;
                }
                catch (const ExtractInvalidCharacterException& e)
                {
                    std::throw_with_nested(ExtractException(
                        E_EXTRACT_ENCODING_ERROR,
                        { input->GetEncodedGlobalFileOffset() + e.GetErrorOffset(), input->CurrentLineNumber() },
                        false));
                }
                catch (const TextConversionException& e)
                {
                    std::throw_with_nested(ExtractException(
                        E_EXTRACT_ROW_ERROR,
                        { e.GetRowNumber(), e.GetColumnIndex(), GetColumnName(e.GetColumnIndex()) },
                        false));
                }
                catch (const RuntimeMemoryException& /* e */)
                {
                    std::throw_with_nested(ScopeStreamExceptionWithEvidence(
                        E_EXTRACT_ROW_TOO_LONG,
                        { input->CurrentLineNumber(), Configuration::GetGlobal().GetMaxInMemoryRowSize() },
                        EvidenceFormatter::FormatText(
                            input->GetBufferStart(),
                            input->GetReadPosition(),
                            input->GetBufferEnd(),
                            input->rowDelimiter,
                            input->delimiter)));
                }
                catch (const ScopeStreamException& e)
                {
                    switch(e.Error())
                    {
                    // Following error will terminate read
                    case ScopeStreamException::EndOfFile:
                    case ScopeStreamException::BadDevice:
                        return false;

                    // Bad rows throw exception
                    case ScopeStreamException::UnexpectedNewLine:
                        // Wrong number of columns in row - report error
                        // At this point, line number is increased to point at the next line. Subtract 1 to get line
                        // number of the offending row.
                        throw ScopeStreamExceptionWithEvidence(
                            E_EXTRACT_UNEXPECTED_ROW_DELIMITER,
                            { input->CurrentLineNumber() - 1, 8, input->CurrentField() },
                            EvidenceFormatter::FormatText(
                                input->GetBufferStart(),
                                input->GetReadPosition(),
                                input->GetBufferEnd(),
                                input->rowDelimiter,
                                input->delimiter));

                    // All exceptions should be handled above.
                    default:
                        SCOPE_ASSERT(false);
                    }
                }
            }
        }
        static const char* GetColumnName(std::size_t columnIndex)
        {
            static const std::array<const char*, 9> c_columnNames =
            {
                "IId",
                "UId",
                "Start",
                "Market",
                "Query",
                "DwellTime",
                "Results",
                "ClickedUrls",
                "*** END ***"
            };

            auto idx = std::min(columnIndex, c_columnNames.size() - 1);
            return c_columnNames[idx];
        }
    };

#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Extract_4_Data0, UID_Output_9>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_4_Data0 & row)
        {
            output->Write<int,false>(row.m_IId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_UId);
            output->WriteDelimiter();
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Market.IsNull())
            {
                output->Write<FString,false>(row.m_Market);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_DwellTime);
            output->WriteDelimiter();
            if (!row.m_Results.IsNull())
            {
                output->Write<FString,false>(row.m_Results);
            }
            output->WriteDelimiter();
            if (!row.m_ClickedUrls.IsNull())
            {
                output->Write<FString,false>(row.m_ClickedUrls);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };

    template<> 
    class TextOutputPolicy<Extract_4_Data0, UID_Output_17>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_4_Data0 & row)
        {
            output->Write<int,false>(row.m_IId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_UId);
            output->WriteDelimiter();
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Market.IsNull())
            {
                output->Write<FString,false>(row.m_Market);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_DwellTime);
            output->WriteDelimiter();
            if (!row.m_Results.IsNull())
            {
                output->Write<FString,false>(row.m_Results);
            }
            output->WriteDelimiter();
            if (!row.m_ClickedUrls.IsNull())
            {
                output->Write<FString,false>(row.m_ClickedUrls);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



    template<> 
    class TextOutputPolicy<SV3_Extract_Split_out4, UID_Output_9>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, SV3_Extract_Split_out4 & row)
        {
            output->Write<int,false>(row.m_IId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_UId);
            output->WriteDelimiter();
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Market.IsNull())
            {
                output->Write<FString,false>(row.m_Market);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_DwellTime);
            output->WriteDelimiter();
            if (!row.m_Results.IsNull())
            {
                output->Write<FString,false>(row.m_Results);
            }
            output->WriteDelimiter();
            if (!row.m_ClickedUrlsCount.IsNull())
            {
                output->Write<FString,false>(row.m_ClickedUrlsCount);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };

    template<> 
    class TextOutputPolicy<SV3_Extract_Split_out4, UID_Output_17>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, SV3_Extract_Split_out4 & row)
        {
            output->Write<int,false>(row.m_IId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_UId);
            output->WriteDelimiter();
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Market.IsNull())
            {
                output->Write<FString,false>(row.m_Market);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_DwellTime);
            output->WriteDelimiter();
            if (!row.m_Results.IsNull())
            {
                output->Write<FString,false>(row.m_Results);
            }
            output->WriteDelimiter();
            if (!row.m_ClickedUrlsCount.IsNull())
            {
                output->Write<FString,false>(row.m_ClickedUrlsCount);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
    template<>
    class InteropToManagedRowPolicy<Extract_4_Data0, UID_Split_5>
    {
    public:
        static void Marshal(Extract_4_Data0& nativeRow, ScopeRuntime::Row^% managedRow, InteropAllocator * alloc)
        {
            alloc->CopyToManagedColumn(nativeRow.m_DwellTime, managedRow[5], 5);
            alloc->CopyToManagedColumn(nativeRow.m_ClickedUrls, managedRow[7], 7);
        }
    };
    template<>
    class InteropToNativeRowPolicy<SV3_Extract_Split_out4, UID_Split_5_4>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, SV3_Extract_Split_out4& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_ClickedUrlsCount, managedRow[7]->Binary, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)

    static const char * StringTable_Split_5_0 [] =
    {
        "Query",
        "IId",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_4_Data0, SV3_Extract_Split_out0, UID_Split_5_0>
    {
    public:
        void Init(ManagedRow<Extract_4_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_4_Data0 & input, SV3_Extract_Split_out0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                    output.m_Query = input.m_Query;
                    exceptionIndex++;
                    output.m_IId1 = input.m_IId;
                    exceptionIndex++;
                    return true;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_5_0[exceptionIndex]));
            }
            }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Split_5_1 [] =
    {
        "IId",
        "UId",
        "Start",
        "Market",
        "Query",
        "DwellTime",
        "Results",
        "ClickedUrls",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_4_Data0, Extract_4_Data0, UID_Split_5_1>
    {
    public:
        void Init(ManagedRow<Extract_4_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_4_Data0 & input, Extract_4_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                    output.m_IId = input.m_IId;
                    exceptionIndex++;
                    output.m_UId = input.m_UId;
                    exceptionIndex++;
                    output.m_Start = input.m_Start;
                    exceptionIndex++;
                    output.m_Market = input.m_Market;
                    exceptionIndex++;
                    output.m_Query = input.m_Query;
                    exceptionIndex++;
                    output.m_DwellTime = input.m_DwellTime;
                    exceptionIndex++;
                    output.m_Results = input.m_Results;
                    exceptionIndex++;
                    output.m_ClickedUrls = input.m_ClickedUrls;
                    exceptionIndex++;
                    return true;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_5_1[exceptionIndex]));
            }
            }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Split_5_2 [] =
    {
        "Market",
        "Results",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_4_Data0, SV3_Extract_Split_out2, UID_Split_5_2>
    {
    public:
        void Init(ManagedRow<Extract_4_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_4_Data0 & input, SV3_Extract_Split_out2 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                    output.m_Market = input.m_Market;
                    exceptionIndex++;
                    output.m_Results = input.m_Results;
                    exceptionIndex++;
                    return true;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_5_2[exceptionIndex]));
            }
            }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Split_5_3 [] =
    {
        "Market",
        "(double)DwellTime",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_4_Data0, SV3_Extract_Split_out3, UID_Split_5_3>
    {
    public:
        void Init(ManagedRow<Extract_4_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_4_Data0 & input, SV3_Extract_Split_out3 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                    output.m_Market = input.m_Market;
                    exceptionIndex++;
                    output.m_DwellTimeDouble = scope_cast<double>(input.m_DwellTime);
                    exceptionIndex++;
                    return true;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_5_3[exceptionIndex]));
            }
            }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };





    class RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4;

    // FilterTransform policy for splitter #4 of Split_5
    template<> 
    class RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>
    {
        RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4* m_tranformPolicyImpl;
        RowTransformPolicy & operator=(RowTransformPolicy &);

    public:
        RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>();
        ~RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>();
        void Init(ManagedRow<Extract_4_Data0> * inputRow);
        bool FilterTransformRow(Extract_4_Data0 & input, SV3_Extract_Split_out4 & output, IncrementalAllocator * alloc);
        ScopeEngine::OperatorRequirements GetOperatorRequirements();
        void InitializeStatics(IncrementalAllocator * alloc);
    };
    
#if defined(COMPILE_MANAGED)
    class RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4
    {
        ScopeTypedManagedHandle<ScopeRuntime::Row^> managedRow[2];
        ScopeTypedManagedHandle<___Scope_Generated_Classes___::ScopeSplitOutputter_7 ^> managedOperator;

    public:
        RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4();
        void Init(ManagedRow<Extract_4_Data0> * inputRow);
        bool FilterTransformRow(Extract_4_Data0 & input, SV3_Extract_Split_out4 & output, IncrementalAllocator * alloc);
        ScopeEngine::OperatorRequirements GetOperatorRequirements();
    };

    // move the implement out of declaration, or it won't generate symbol
    RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4::RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4()
    {
    }

    void RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4::Init(ManagedRow<Extract_4_Data0> * inputRow)
    {
        managedRow[0] = inputRow->get();
        managedRow[1] = gcnew ___Scope_Generated_Classes___::Row_2EDD8A91968976D1();
        managedOperator = gcnew ___Scope_Generated_Classes___::ScopeSplitOutputter_7();
    }

    bool RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4::FilterTransformRow(Extract_4_Data0 & input, SV3_Extract_Split_out4 & output, IncrementalAllocator * alloc)
    {
            if (managedOperator->EvaluateTransform(managedRow[0].get(), managedRow[1].get()))
            {
                InteropToNativeRowPolicy<SV3_Extract_Split_out4, UID_Split_5_4>::Marshal(managedRow[1].get(), output, alloc);
                output.m_IId = input.m_IId;
                output.m_UId = input.m_UId;
                output.m_Start = input.m_Start;
                output.m_Market = input.m_Market;
                output.m_Query = input.m_Query;
                output.m_DwellTime = input.m_DwellTime;
                output.m_Results = input.m_Results;
                return true;
            }

            return false;
    }

    ScopeEngine::OperatorRequirements RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4::GetOperatorRequirements()
    {
        return ScopeEngine::OperatorRequirements();
    }

    RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>::RowTransformPolicy()
    {
        m_tranformPolicyImpl = new RowTransformPolicy_Extract_4_Data0_SV3_Extract_Split_out4_UID_Split_5_4();
    }

    RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>::~RowTransformPolicy()
    {
        if (m_tranformPolicyImpl != NULL)
        {
            delete m_tranformPolicyImpl;
            m_tranformPolicyImpl = NULL;
        }
    }

    void RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>::Init(ManagedRow<Extract_4_Data0> * inputRow)
    {
        m_tranformPolicyImpl->Init(inputRow);
    }

    bool RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>::FilterTransformRow(Extract_4_Data0 & input, SV3_Extract_Split_out4 & output, IncrementalAllocator * alloc)
    {
        return m_tranformPolicyImpl->FilterTransformRow(input, output, alloc);
    }

    void RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>::InitializeStatics(IncrementalAllocator * alloc)
    {

    }

    ScopeEngine::OperatorRequirements RowTransformPolicy<typename Extract_4_Data0, typename SV3_Extract_Split_out4, UID_Split_5_4>::GetOperatorRequirements()
    {
        return m_tranformPolicyImpl->GetOperatorRequirements();
    }

#endif // defined(COMPILE_MANAGED)


    class SplitPolicy_Extract_4_Data0_UID_Split_5
    {
    public:
        virtual ManagedRow<Extract_4_Data0>* GetManagedRow() = 0;
        virtual void Marshal(Extract_4_Data0 & input) = 0;

        static SplitPolicy_Extract_4_Data0_UID_Split_5* CreateInstance();
    };

#if defined(COMPILE_MANAGED)
    
    class SplitPolicy_Extract_4_Data0_UID_Split_5Impl : public SplitPolicy_Extract_4_Data0_UID_Split_5
    {
        ManagedRow<Extract_4_Data0> m_managedRow;
        
        InteropAllocator m_allocator;

    public:
        SplitPolicy_Extract_4_Data0_UID_Split_5Impl();
        ManagedRow<Extract_4_Data0>* GetManagedRow();
        void Marshal(Extract_4_Data0 & input);
    };

    SplitPolicy_Extract_4_Data0_UID_Split_5Impl::SplitPolicy_Extract_4_Data0_UID_Split_5Impl()
      
        : m_allocator(8, "SplitPolicy_Extract_4_Data0_UID_Split_5Impl")
    {
    }

    ManagedRow<Extract_4_Data0>* SplitPolicy_Extract_4_Data0_UID_Split_5Impl::GetManagedRow()
    {
        return &m_managedRow;
    }

    void SplitPolicy_Extract_4_Data0_UID_Split_5Impl::Marshal(Extract_4_Data0 & input)
    {
        InteropToManagedRowPolicy<Extract_4_Data0, UID_Split_5>::Marshal(input, m_managedRow.get(), &m_allocator);
    }

    SplitPolicy_Extract_4_Data0_UID_Split_5* SplitPolicy_Extract_4_Data0_UID_Split_5::CreateInstance()
    {
        return new SplitPolicy_Extract_4_Data0_UID_Split_5Impl();
    }

#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<> 
    class SplitPolicy<typename Extract_4_Data0, UID_Split_5>
    {
        SIZE_T m_outputBufSize;
        int m_outputBufCnt;

        typedef SplitOutputterSentinel<Extract_4_Data0> SplitOutputType_Split_5_5;
        SplitOutputType_Split_5_5 splitOutputter_Split_5_5;

        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<SV3_Extract_Split_out4, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, TextOutputPolicy<SV3_Extract_Split_out4, UID_Output_17>> OutputPolicyWrapperType_Split_5_4;

        typedef SplitOutputter<
            SplitOutputType_Split_5_5, 
            SV3_Extract_Split_out4, 
            OutputPolicyWrapperType_Split_5_4, 
            ExecutionStats, 
            UID_Split_5_4> 
            SplitOutputType_Split_5_4;

        SplitOutputType_Split_5_4 splitOutputter_Split_5_4;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<SV3_Extract_Split_out3, BinaryOutputStream, BinaryOutputPolicy<SV3_Extract_Split_out3>> OutputPolicyWrapperType_Split_5_3;

        typedef SplitOutputter<
            SplitOutputType_Split_5_4, 
            SV3_Extract_Split_out3, 
            OutputPolicyWrapperType_Split_5_3, 
            ExecutionStats, 
            UID_Split_5_3> 
            SplitOutputType_Split_5_3;

        SplitOutputType_Split_5_3 splitOutputter_Split_5_3;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<SV3_Extract_Split_out2, BinaryOutputStream, BinaryOutputPolicy<SV3_Extract_Split_out2>> OutputPolicyWrapperType_Split_5_2;

        typedef SplitOutputter<
            SplitOutputType_Split_5_3, 
            SV3_Extract_Split_out2, 
            OutputPolicyWrapperType_Split_5_2, 
            ExecutionStats, 
            UID_Split_5_2> 
            SplitOutputType_Split_5_2;

        SplitOutputType_Split_5_2 splitOutputter_Split_5_2;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<Extract_4_Data0, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, TextOutputPolicy<Extract_4_Data0, UID_Output_9>> OutputPolicyWrapperType_Split_5_1;

        typedef SplitOutputter<
            SplitOutputType_Split_5_2, 
            Extract_4_Data0, 
            OutputPolicyWrapperType_Split_5_1, 
            ExecutionStats, 
            UID_Split_5_1> 
            SplitOutputType_Split_5_1;

        SplitOutputType_Split_5_1 splitOutputter_Split_5_1;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<SV3_Extract_Split_out0, BinaryOutputStream, BinaryOutputPolicy<SV3_Extract_Split_out0>> OutputPolicyWrapperType_Split_5_0;

        typedef SplitOutputter<
            SplitOutputType_Split_5_1, 
            SV3_Extract_Split_out0, 
            OutputPolicyWrapperType_Split_5_0, 
            ExecutionStats, 
            UID_Split_5_0> 
            SplitOutputType_Split_5_0;

        SplitOutputType_Split_5_0 splitOutputter_Split_5_0;


        unique_ptr<SplitPolicy_Extract_4_Data0_UID_Split_5> m_splitPolicyWrapper;
    public:
        SplitPolicy(OutputFileInfo * outputFiles, SIZE_T outputBufSize, int outputBufCnt) : m_outputBufSize(outputBufSize), m_outputBufCnt(outputBufCnt),
            splitOutputter_Split_5_4(&splitOutputter_Split_5_5, new OutputPolicyWrapperType_Split_5_4(outputFiles[4].outputFileName, outputBufSize, outputBufCnt, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), false), outputFiles[4].outputFileName, false, UID_SV3_Extract_Split_out4),
            splitOutputter_Split_5_3(&splitOutputter_Split_5_4, new OutputPolicyWrapperType_Split_5_3(outputFiles[3].outputFileName, outputBufSize, outputBufCnt, false), outputFiles[3].outputFileName, false, UID_SV3_Extract_Split_out3),
            splitOutputter_Split_5_2(&splitOutputter_Split_5_3, new OutputPolicyWrapperType_Split_5_2(outputFiles[2].outputFileName, outputBufSize, outputBufCnt, false), outputFiles[2].outputFileName, false, UID_SV3_Extract_Split_out2),
            splitOutputter_Split_5_1(&splitOutputter_Split_5_2, new OutputPolicyWrapperType_Split_5_1(outputFiles[1].outputFileName, outputBufSize, outputBufCnt, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), false), outputFiles[1].outputFileName, false, UID_SV3_Extract_Split_out1),
            splitOutputter_Split_5_0(&splitOutputter_Split_5_1, new OutputPolicyWrapperType_Split_5_0(outputFiles[0].outputFileName, outputBufSize, outputBufCnt, false), outputFiles[0].outputFileName, false, UID_SV3_Extract_Split_out0)
        {
        }

        void SetSequenceNumber(int sequenceNumber)
        {
            splitOutputter_Split_5_4.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_5_3.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_5_2.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_5_1.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_5_0.SetSequenceNumber(sequenceNumber);
        }

        void Init()
        {
            m_splitPolicyWrapper.reset(SplitPolicy_Extract_4_Data0_UID_Split_5::CreateInstance());
            
            splitOutputter_Split_5_0.Init(m_splitPolicyWrapper->GetManagedRow());
        }

        void BeginDataRead()
        {
            splitOutputter_Split_5_0.BeginDataRead();
        }

        void Close()
        {
            splitOutputter_Split_5_0.Close();
        }

        void ProcessMetadata(PartitionMetadata * metadata)
        {
            splitOutputter_Split_5_0.ProcessMetadata(metadata);
        }

        void OutputHeader()
        {
            splitOutputter_Split_5_0.OutputHeader();
        }

        void ProcessRow(Extract_4_Data0 & input)
        {
            m_splitPolicyWrapper->Marshal(input);
            splitOutputter_Split_5_0.ProcessRow(input);
        }

        __declspec(noinline)
        void WriteRuntimeStats(TreeNode & root) const
        {
            splitOutputter_Split_5_0.WriteRuntimeStats(root);
        }

        LONGLONG GetTotalIoWaitTime() const
        {
            return splitOutputter_Split_5_0.GetTotalIoWaitTime();
        }

        // get operator resource requirements
        ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return splitOutputter_Split_5_0.GetOperatorRequirements()
	.AddMemoryForOutputUStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), m_outputBufCnt)
	.AddMemoryForOutputUStreams(1, m_outputBufSize, m_outputBufCnt)
	.AddMemoryForOutputUStreams(1, m_outputBufSize, m_outputBufCnt)
	.AddMemoryForOutputUStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), m_outputBufCnt)
	.AddMemoryForOutputUStreams(1, m_outputBufSize, m_outputBufCnt);
        }

        void FlushOutput(bool forcePersistent = false)
        {
            splitOutputter_Split_5_0.FlushOutput(forcePersistent);
        }

    };

#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV3_Extract_Split_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
            // move all empty inputs to the end of extractor array so we can always get metadata from the first input
            std::stable_partition(&inputs[0], inputs + inputCnt - 0, [](const InputFileInfo& input){ return input.length != 0; });
        }
        // Define extractor type and construct objects
        // 
        typedef Extractor<Extract_4_Data0, TextExtractPolicy<Extract_4_Data0, UID_Extract_4>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> ExtractorType1_SV3_Extr_Split;
        unique_ptr<unique_ptr<ExtractorType1_SV3_Extr_Split>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV3_Extr_Split>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            // 
            extractor_0_array[i - 0].reset(new ExtractorType1_SV3_Extr_Split(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_4));
        }

    ExtractorType1_SV3_Extr_Split ** extractor_0 = (ExtractorType1_SV3_Extr_Split **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;
        // Merge streams N->1
        typedef ParallelUnionAll<ExtractorType1_SV3_Extr_Split, Extract_4_Data0, IsNativeOnlyVertex> UnionAllType_Extract_4_Split_5_connector;
        unique_ptr<UnionAllType_Extract_4_Split_5_connector> unionall_Extract_4_Split_5_connector_ptr(new UnionAllType_Extract_4_Split_5_connector(extractor_0,extractor_0_count,12,419430400,UID_ParallelUnionAll_Extract_4));
        UnionAllType_Extract_4_Split_5_connector * unionall_Extract_4_Split_5_connector = unionall_Extract_4_Split_5_connector_ptr.get();
        ULONG unionall_Extract_4_Split_5_connector_count = 1;
        // Define splitter type

        typedef Splitter<UnionAllType_Extract_4_Split_5_connector, Extract_4_Data0, false, UID_Split_5> SplitterType_Split_5;

        // Construct operator and initialize it.
        unique_ptr<SplitterType_Split_5> splitter_Split_5_ptr (new SplitterType_Split_5(unionall_Extract_4_Split_5_connector, outputs, x_outputBufSize, x_outputBufCnt, UID_Split_5, false));
        SplitterType_Split_5 * splitter_Split_5 = splitter_Split_5_ptr.get();

        if (argv != nullptr && argc > 0)
        {
            try
            {
                int sequenceNumber = GetSequenceNumber(argv, argc);
                splitter_Split_5->SetSequenceNumber(sequenceNumber);
            }
            catch(const RuntimeException&)
            {
                // Sequence number will remain 0 in splitter_Split_5.
            }
        }

        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *splitter_Split_5) };

        try
        {
            // Init operator chain
            splitter_Split_5->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_4_Data0 row;
            splitter_Split_5->GetNextRow(row);

            // Close operator chain
            splitter_Split_5->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        splitter_Split_5->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV3_Extract_Split
#pragma region SV4_Process
#if defined(COMPILE_SV4_PROCESS) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<SV3_Extract_Split_out0,UID_Process_6>
    {
    public:
        struct KeyStruct
        {
            int m_IId1;

            KeyStruct(SV3_Extract_Split_out0 & c) :
                m_IId1(c.m_IId1)
            {
            }

            KeyStruct(const SV3_Extract_Split_out0 & c, IncrementalAllocator * alloc) :
                m_IId1(const_cast<SV3_Extract_Split_out0&>(c).m_IId1)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_IId1(c.m_IId1)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_IId1(const_cast<KeyStruct&>(c).m_IId1)
            {
            }

            KeyStruct() :
                m_IId1(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"IId1:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV3_Extract_Split_out0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_IId1, key.m_IId1)) != 0)
                return r;
            return r;
        }

        static int Compare(SV3_Extract_Split_out0 * n1, SV3_Extract_Split_out0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_IId1, (*n2).m_IId1)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(SV3_Extract_Split_out0 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_IId1);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(SV3_Extract_Split_out0 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };




#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV4_Process_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // Define extractor type and construct object
        typedef Extractor<SV3_Extract_Split_out0, BinaryExtractPolicy<SV3_Extract_Split_out0>, BinaryInputStream> ExtractorType1_SV4_Proc;        
        unique_ptr<ExtractorType1_SV4_Proc> extractor_0_ptr= make_unique<ExtractorType1_SV4_Proc>(inputs[0], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV3_Extract_Split_out0);
        ExtractorType1_SV4_Proc * extractor_0 = extractor_0_ptr.get();
        ULONG extractor_0_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<SV3_Extract_Split_out0>> delegate_extractor_0_ptr (new OperatorDelegate<SV3_Extract_Split_out0>(OperatorDelegate<SV3_Extract_Split_out0>::FromOperator(extractor_0)));
        OperatorDelegate<SV3_Extract_Split_out0> * delegate_extractor_0 = delegate_extractor_0_ptr.get();
        ULONG delegate_extractor_0_count = 1;
        // Define sorter type
        typedef Sorter<SV3_Extract_Split_out0> SorterType_Process_6;
        // Construct operator and initialize it.
        unique_ptr<SorterType_Process_6> sorter_Process_6_ptr (new SorterType_Process_6(delegate_extractor_0, &StdSort<SV3_Extract_Split_out0>::Sort<KeyComparePolicy<SV3_Extract_Split_out0, UID_Process_6>, (sizeof(SV3_Extract_Split_out0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<SV3_Extract_Split_out0>::CreateDelegate<UID_Process_6>(), false, 5597298664 /*memoryQuota*/, UID_Process_6));
        SorterType_Process_6 * sorter_Process_6 = sorter_Process_6_ptr.get();
        ULONG sorter_Process_6_count = 1;
        // Define outputter type
        typedef Outputter<SorterType_Process_6, SV3_Extract_Split_out0, BinaryOutputPolicy<SV3_Extract_Split_out0>, BinaryOutputStream, false> OutputterType2_SV4_Proc;
        // Construct operator and initialize it
        unique_ptr<OutputterType2_SV4_Proc> outputter_SV4_Process_out0_ptr(new OutputterType2_SV4_Proc(sorter_Process_6, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, UID_SV4_Process_out0, false));
        OutputterType2_SV4_Proc * outputter_SV4_Process_out0 = outputter_SV4_Process_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV4_Process_out0) };

        try
        {
            // Init operator chain
            outputter_SV4_Process_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            SV3_Extract_Split_out0 row;
            outputter_SV4_Process_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV4_Process_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV4_Process_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV4_Process
#pragma region SV5_Combine
#if defined(COMPILE_SV5_COMBINE) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<SV1_Extract_Split_out1,UID_Join_7_0>
    {
    public:
        struct KeyStruct
        {
            int m_IId;

            KeyStruct(SV1_Extract_Split_out1 & c) :
                m_IId(c.m_IId)
            {
            }

            KeyStruct(const SV1_Extract_Split_out1 & c, IncrementalAllocator * alloc) :
                m_IId(const_cast<SV1_Extract_Split_out1&>(c).m_IId)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_IId(c.m_IId)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_IId(const_cast<KeyStruct&>(c).m_IId)
            {
            }

            KeyStruct() :
                m_IId(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"IId:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV1_Extract_Split_out1 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_IId, key.m_IId)) != 0)
                return r;
            return r;
        }

        static int Compare(SV1_Extract_Split_out1 * n1, SV1_Extract_Split_out1 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_IId, (*n2).m_IId)) != 0)
                return r;
            return r;
        }

    };




    template<> 
    class KeyComparePolicy<SV3_Extract_Split_out0,UID_Join_7_1>
    {
    public:
        struct KeyStruct
        {
            int m_IId1;

            KeyStruct(SV3_Extract_Split_out0 & c) :
                m_IId1(c.m_IId1)
            {
            }

            KeyStruct(const SV3_Extract_Split_out0 & c, IncrementalAllocator * alloc) :
                m_IId1(const_cast<SV3_Extract_Split_out0&>(c).m_IId1)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_IId1(c.m_IId1)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_IId1(const_cast<KeyStruct&>(c).m_IId1)
            {
            }

            KeyStruct() :
                m_IId1(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"IId1:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV3_Extract_Split_out0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_IId1, key.m_IId1)) != 0)
                return r;
            return r;
        }

        static int Compare(SV3_Extract_Split_out0 * n1, SV3_Extract_Split_out0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_IId1, (*n2).m_IId1)) != 0)
                return r;
            return r;
        }

    };



#if defined(COMPILE_NATIVE)
    template<>
    class RowHashPolicy<SV1_Extract_Split_out1,UID_Join_7>
    {
    public:
        static __int64 Hash(SV1_Extract_Split_out1* row)
        {
            ScopeRowHasher hasher;
            hasher.HashColumnValue<int> ((*row).m_IId);
            return hasher.ComputeHashCode();
        }

        INLINE static int Bucket(SV1_Extract_Split_out1* row, int bucketCount)
        {
            return ScopeRowHasher::ComputeBucket(Hash(row), bucketCount);
        }
    };

#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<> 
    class CombinerPolicy<UID_Join_7> 
    {
    public:
        typedef KeyComparePolicy<SV1_Extract_Split_out1,UID_Join_7_0> LeftKeyPolicy;
        typedef KeyComparePolicy<SV3_Extract_Split_out0,UID_Join_7_1> RightKeyPolicy;

        static constexpr unsigned MaxPerKeyCrossSizeLimit = 0;

        static LONGLONG JoinerMemQuota()
        {
            return 1737490290ULL;
        }

        // compare key from left and right schema object
        static int Compare(const SV1_Extract_Split_out1 * left, const SV3_Extract_Split_out0 * right)
        {
            int r = 0;
            SV1_Extract_Split_out1 * n1 = const_cast<SV1_Extract_Split_out1 *>(left);
            SV3_Extract_Split_out0 * n2 = const_cast<SV3_Extract_Split_out0 *>(right);

            if ((r = ScopeTypeCompare((*n1).m_IId, (*n2).m_IId1)) != 0)
                return r;
            
            // Everything matches
            return 0;
        }

        static void CopyRow(SV1_Extract_Split_out1 * left, SV3_Extract_Split_out0 * right, Join_7_Data0 * out)
        {
                (*out).m_AdId = (*left).m_AdId;
                (*out).m_IId = (*left).m_IId;
                (*out).m_Impression = (*left).m_Impression;
                (*out).m_Query = (*right).m_Query;
        }

        static void CopyLeftRow(SV1_Extract_Split_out1 * left, Join_7_Data0 * out)
        {
            (*out).m_AdId = (*left).m_AdId;
            (*out).m_IId = (*left).m_IId;
            (*out).m_Impression = (*left).m_Impression;
        }

        static void NullifyRightSide(Join_7_Data0 * out)
        {
            (*out).m_Query.SetNull();
        }

        static void CopyRightRow(SV3_Extract_Split_out0 * right, Join_7_Data0 * out)
        {
            (*out).m_Query = (*right).m_Query;
        }

        static void NullifyLeftSide(Join_7_Data0 * out)
        {
        }
    };
#endif // defined(COMPILE_NATIVE)




    template<> 
    class TextOutputPolicy<Join_7_Data0, UID_SV5_Combine_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Join_7_Data0 & row)
        {
            output->Write<int,false>(row.m_AdId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_IId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Impression);
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV5_Combine_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // Define extractor type and construct object
        typedef Extractor<SV1_Extract_Split_out1, BinaryExtractPolicy<SV1_Extract_Split_out1>, BinaryInputStream> ExtractorType1_SV5_Cmbn;        
        unique_ptr<ExtractorType1_SV5_Cmbn> extractor_0_ptr= make_unique<ExtractorType1_SV5_Cmbn>(inputs[0], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV2_Process_out0);
        ExtractorType1_SV5_Cmbn * extractor_0 = extractor_0_ptr.get();
        ULONG extractor_0_count = 1;
        // Define extractor type and construct object
        typedef Extractor<SV3_Extract_Split_out0, BinaryExtractPolicy<SV3_Extract_Split_out0>, BinaryInputStream> ExtractorType2_SV5_Cmbn;        
        unique_ptr<ExtractorType2_SV5_Cmbn> extractor_1_ptr= make_unique<ExtractorType2_SV5_Cmbn>(inputs[1], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV4_Process_out0);
        ExtractorType2_SV5_Cmbn * extractor_1 = extractor_1_ptr.get();
        ULONG extractor_1_count = 1;

        // Define the combiner operator
        typedef NativeCombinerWrapper<ExtractorType1_SV5_Cmbn, SV1_Extract_Split_out1, ExtractorType2_SV5_Cmbn, SV3_Extract_Split_out0, Join_7_Data0, InnerJoiner, UID_Join_7> CombinerType_Join_7;
        unique_ptr<CombinerType_Join_7> combiner_Join_7_ptr;
        combiner_Join_7_ptr.reset(new CombinerType_Join_7(extractor_0, extractor_1, UID_Join_7, 0, false, nullptr));
 
        CombinerType_Join_7 * combiner_Join_7 = combiner_Join_7_ptr.get();
        ULONG combiner_Join_7_count = 1;
        // Define outputter type
        typedef Outputter<CombinerType_Join_7, Join_7_Data0, TextOutputPolicy<Join_7_Data0, UID_SV5_Combine_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false> OutputterType3_SV5_Cmbn;
        // Construct operator and initialize it
        unique_ptr<OutputterType3_SV5_Cmbn> outputter_SV5_Combine_out0_ptr(new OutputterType3_SV5_Cmbn(combiner_Join_7, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV5_Combine_out0));
        OutputterType3_SV5_Cmbn * outputter_SV5_Combine_out0 = outputter_SV5_Combine_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV5_Combine_out0) };

        try
        {
            // Init operator chain
            outputter_SV5_Combine_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Join_7_Data0 row;
            outputter_SV5_Combine_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV5_Combine_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV5_Combine_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV5_Combine
#pragma region SV6_Process
#if defined(COMPILE_SV6_PROCESS) || defined(COMPILE_ALL_VERTICES)

    static const char * StringTable_Process_11 [] =
    {
        "Market",
        "SplitResult",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Process_10_Data0, Process_11_Data0, UID_Process_11>
    {
    public:
        static bool FilterTransformRow(Process_10_Data0 & input, Process_11_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                    output.m_Market = input.m_Market;
                    exceptionIndex++;
                    output.m_Result = input.m_SplitResult;
                    exceptionIndex++;
                    return true;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_11[exceptionIndex]));
            }
            }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };




#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<>
    class RowTransformPolicy<SV3_Extract_Split_out2, Process_10_Data0, UID_Process_10>
    {
    public:
        static bool FilterTransformRow(SV3_Extract_Split_out2 & input, Process_10_Data0 & output, IncrementalAllocator * alloc)
        {
return true;
    }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements().AddMemoryInRows(1, 1);
        }
    };




#if defined(COMPILE_MANAGED)
    template<>
    struct ManagedUDO<UID_Process_10>
    {
        typedef ScopeRuntime::Processor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Process_10());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{})));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Process_10, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_Market_String_SplitResult_String();
            m_udo->GetType()->GetField("_outputRow", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), curRow);
            m_udo->GetType()->GetField("_outputSchema", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), m_udo->DefaultRow->Schema);
        }


        UDO^ get()
        {
            return m_udo.get();
        }

        Generic::List<String^>^ args()
        {
            return m_args.get();
        }

    private:
        ScopeTypedManagedHandle<UDO^> m_udo;
        ScopeTypedManagedHandle<Generic::List<String^>^> m_args;
        ManagedUDO & operator=(ManagedUDO &);
    };
    template<>
    class InteropToManagedRowPolicy<SV3_Extract_Split_out2, UID_Process_10>
    {
    public:
        static void Marshal(SV3_Extract_Split_out2& nativeRow, ScopeRuntime::Row^% managedRow, InteropAllocator * alloc)
        {
            alloc->CopyToManagedColumn(nativeRow.m_Market, managedRow[0], 0);
            alloc->CopyToManagedColumn(nativeRow.m_Results, managedRow[1], 1);
        }
    };
    template<>
    class InteropToNativeRowPolicy<Process_10_Data0, UID_Process_10>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Process_10_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Market, managedRow[0]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_SplitResult, managedRow[1]->Binary, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Process_11_Data0, UID_SV6_Process_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Process_11_Data0 & row)
        {
            if (!row.m_Market.IsNull())
            {
                output->Write<FString,false>(row.m_Market);
            }
            output->WriteDelimiter();
            if (!row.m_Result.IsNull())
            {
                output->Write<FString,false>(row.m_Result);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV6_Process_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // Define extractor type and construct object
        typedef Extractor<SV3_Extract_Split_out2, BinaryExtractPolicy<SV3_Extract_Split_out2>, BinaryInputStream> ExtractorType1_SV6_Proc;        
        unique_ptr<ExtractorType1_SV6_Proc> extractor_0_ptr= make_unique<ExtractorType1_SV6_Proc>(inputs[0], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV3_Extract_Split_out2);
        ExtractorType1_SV6_Proc * extractor_0 = extractor_0_ptr.get();
        ULONG extractor_0_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<SV3_Extract_Split_out2>> delegate_extractor_0_ptr (new OperatorDelegate<SV3_Extract_Split_out2>(OperatorDelegate<SV3_Extract_Split_out2>::FromOperator(extractor_0)));
        OperatorDelegate<SV3_Extract_Split_out2> * delegate_extractor_0 = delegate_extractor_0_ptr.get();
        ULONG delegate_extractor_0_count = 1;
        // Define the type of the operator
        typedef ScopeProcessor<SV3_Extract_Split_out2, Process_10_Data0> ProcessorType_Process_10;
        // Construct operator and initialize it.
        unique_ptr<ProcessorType_Process_10> processor_Process_10_ptr (new ProcessorType_Process_10(ScopeApplierManagedFactory::Make<SV3_Extract_Split_out2,Process_10_Data0,UID_Process_10>(delegate_extractor_0), delegate_extractor_0, UID_Process_10));
        ProcessorType_Process_10 * processor_Process_10 = processor_Process_10_ptr.get();
        ULONG processor_Process_10_count = 1;
        // Define the type of the operator
        typedef FilterTransformer<ProcessorType_Process_10, Process_10_Data0, Process_11_Data0, UID_Process_11> FilterTransformerType_Process_11;
        // Construct operator and initialize it.
        unique_ptr<FilterTransformerType_Process_11> filterTransformer_Process_11_ptr (new FilterTransformerType_Process_11(processor_Process_10, UID_Process_11));
        FilterTransformerType_Process_11 * filterTransformer_Process_11 = filterTransformer_Process_11_ptr.get();
        ULONG filterTransformer_Process_11_count = 1;
        // Define outputter type
        typedef Outputter<FilterTransformerType_Process_11, Process_11_Data0, TextOutputPolicy<Process_11_Data0, UID_SV6_Process_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false> OutputterType2_SV6_Proc;
        // Construct operator and initialize it
        unique_ptr<OutputterType2_SV6_Proc> outputter_SV6_Process_out0_ptr(new OutputterType2_SV6_Proc(filterTransformer_Process_11, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV6_Process_out0));
        OutputterType2_SV6_Proc * outputter_SV6_Process_out0 = outputter_SV6_Process_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV6_Process_out0) };

        try
        {
            // Init operator chain
            outputter_SV6_Process_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_11_Data0 row;
            outputter_SV6_Process_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV6_Process_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV6_Process_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
template ScopeProcessorManaged<SV3_Extract_Split_out2, Process_10_Data0> * ScopeEngine::ScopeApplierManagedFactory::Make<SV3_Extract_Split_out2, Process_10_Data0, UID_Process_10>(OperatorDelegate<SV3_Extract_Split_out2>*);
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV6_Process
#pragma region SV7_Process
#if defined(COMPILE_SV7_PROCESS) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<SV3_Extract_Split_out3,UID_Process_13>
    {
    public:
        struct KeyStruct
        {
            FString m_Market;

            KeyStruct(SV3_Extract_Split_out3 & c) :
                m_Market(c.m_Market)
            {
            }

            KeyStruct(const SV3_Extract_Split_out3 & c, IncrementalAllocator * alloc) :
                m_Market(const_cast<SV3_Extract_Split_out3&>(c).m_Market, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Market(c.m_Market)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Market(const_cast<KeyStruct&>(c).m_Market, alloc)
            {
            }

            KeyStruct() :
                m_Market()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Market:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV3_Extract_Split_out3 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Market, key.m_Market)) != 0)
                return r;
            return r;
        }

        static int Compare(SV3_Extract_Split_out3 * n1, SV3_Extract_Split_out3 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Market, (*n2).m_Market)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(SV3_Extract_Split_out3 * p, int depth)
        {
            if (depth < 1 && (*p).m_Market.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_Market.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_Market.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_Market.buffer()[depth]));
            }

            depth -= (int) ((*p).m_Market.size() + 1);


            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(SV3_Extract_Split_out3 * p, int depth)
        {
            depth -= (int) ((*p).m_Market.size() + 1);
            if (depth < 0)
                return false;
            return true;
        }
    };



    static const char * StringTable_Process_14 [] =
    {
        "Market",
        "DwellTimeDouble",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<SV3_Extract_Split_out3, Process_14_Data0, UID_Process_14>
    {
    public:
        static bool FilterTransformRow(SV3_Extract_Split_out3 & input, Process_14_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                    output.m_Market = input.m_Market;
                    exceptionIndex++;
                    output.m_TotalDwellTime = input.m_DwellTimeDouble;
                    exceptionIndex++;
                    return true;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_14[exceptionIndex]));
            }
            }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };




#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<>
    class RowTransformPolicy<Process_14_Data0, Process_14_Data0, UID_Process_15>
    {
    public:
        static bool FilterTransformRow(Process_14_Data0 & input, Process_14_Data0 & output, IncrementalAllocator * alloc)
        {
return true;
    }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements().AddMemoryInRows(1, 1);
        }
    };




#if defined(COMPILE_MANAGED)
    template<>
    struct ManagedUDO<UID_Process_15>
    {
        typedef ScopeRuntime::Processor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Process_15());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{})));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Process_15, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_Market_String_TotalDwellTime_Double();
            m_udo->GetType()->GetField("_outputRow", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), curRow);
            m_udo->GetType()->GetField("_outputSchema", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), m_udo->DefaultRow->Schema);
        }


        UDO^ get()
        {
            return m_udo.get();
        }

        Generic::List<String^>^ args()
        {
            return m_args.get();
        }
        cli::array<String^>^ ReadOnlyColumns_Output()
        {
            return nullptr;
        }

        cli::array<String^>^ ReadOnlyColumns_Input()
        {
            return nullptr;
        }

    private:
        ScopeTypedManagedHandle<UDO^> m_udo;
        ScopeTypedManagedHandle<Generic::List<String^>^> m_args;
        ManagedUDO & operator=(ManagedUDO &);
    };
    template<>
    class InteropToManagedRowPolicy<Process_14_Data0, UID_Process_15>
    {
    public:
        static void Marshal(Process_14_Data0& nativeRow, ScopeRuntime::Row^% managedRow, InteropAllocator * alloc)
        {
            alloc->CopyToManagedColumn(nativeRow.m_Market, managedRow[0], 0);
            alloc->CopyToManagedColumn(nativeRow.m_TotalDwellTime, managedRow[1], 1);
        }
    };
    template<>
    class InteropToNativeRowPolicy<Process_14_Data0, UID_Process_15>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Process_14_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Market, managedRow[0]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_TotalDwellTime, managedRow[1]->Double, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Process_14_Data0, UID_SV7_Process_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Process_14_Data0 & row)
        {
            if (!row.m_Market.IsNull())
            {
                output->Write<FString,false>(row.m_Market);
            }
            output->WriteDelimiter();
            output->Write<double,false>(row.m_TotalDwellTime);
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV7_Process_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // Define extractor type and construct object
        typedef Extractor<SV3_Extract_Split_out3, BinaryExtractPolicy<SV3_Extract_Split_out3>, BinaryInputStream> ExtractorType1_SV7_Proc;        
        unique_ptr<ExtractorType1_SV7_Proc> extractor_0_ptr= make_unique<ExtractorType1_SV7_Proc>(inputs[0], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV3_Extract_Split_out3);
        ExtractorType1_SV7_Proc * extractor_0 = extractor_0_ptr.get();
        ULONG extractor_0_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<SV3_Extract_Split_out3>> delegate_extractor_0_ptr (new OperatorDelegate<SV3_Extract_Split_out3>(OperatorDelegate<SV3_Extract_Split_out3>::FromOperator(extractor_0)));
        OperatorDelegate<SV3_Extract_Split_out3> * delegate_extractor_0 = delegate_extractor_0_ptr.get();
        ULONG delegate_extractor_0_count = 1;
        // Define sorter type
        typedef Sorter<SV3_Extract_Split_out3> SorterType_Process_13;
        // Construct operator and initialize it.
        unique_ptr<SorterType_Process_13> sorter_Process_13_ptr (new SorterType_Process_13(delegate_extractor_0, &MKQSort<SV3_Extract_Split_out3>::Sort<KeyComparePolicy<SV3_Extract_Split_out3, UID_Process_13>, (sizeof(SV3_Extract_Split_out3)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<SV3_Extract_Split_out3>::CreateDelegate<UID_Process_13>(), false, 2399141696 /*memoryQuota*/, UID_Process_13));
        SorterType_Process_13 * sorter_Process_13 = sorter_Process_13_ptr.get();
        ULONG sorter_Process_13_count = 1;
        // Define the type of the operator
        typedef FilterTransformer<SorterType_Process_13, SV3_Extract_Split_out3, Process_14_Data0, UID_Process_14> FilterTransformerType_Process_14;
        // Construct operator and initialize it.
        unique_ptr<FilterTransformerType_Process_14> filterTransformer_Process_14_ptr (new FilterTransformerType_Process_14(sorter_Process_13, UID_Process_14));
        FilterTransformerType_Process_14 * filterTransformer_Process_14 = filterTransformer_Process_14_ptr.get();
        ULONG filterTransformer_Process_14_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<Process_14_Data0>> delegate_filterTransformer_Process_14_ptr (new OperatorDelegate<Process_14_Data0>(OperatorDelegate<Process_14_Data0>::FromOperator(filterTransformer_Process_14)));
        OperatorDelegate<Process_14_Data0> * delegate_filterTransformer_Process_14 = delegate_filterTransformer_Process_14_ptr.get();
        ULONG delegate_filterTransformer_Process_14_count = 1;
        // Define the type of the operator
        typedef ScopeProcessor<Process_14_Data0, Process_14_Data0> ProcessorType_Process_15;
        // Construct operator and initialize it.
        unique_ptr<ProcessorType_Process_15> processor_Process_15_ptr (new ProcessorType_Process_15(ScopeGrouperManagedFactory::Make<Process_14_Data0,Process_14_Data0,UID_Process_15>(delegate_filterTransformer_Process_14), delegate_filterTransformer_Process_14, UID_Process_15));
        ProcessorType_Process_15 * processor_Process_15 = processor_Process_15_ptr.get();
        ULONG processor_Process_15_count = 1;
        // Define outputter type
        typedef Outputter<ProcessorType_Process_15, Process_14_Data0, TextOutputPolicy<Process_14_Data0, UID_SV7_Process_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false> OutputterType2_SV7_Proc;
        // Construct operator and initialize it
        unique_ptr<OutputterType2_SV7_Proc> outputter_SV7_Process_out0_ptr(new OutputterType2_SV7_Proc(processor_Process_15, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV7_Process_out0));
        OutputterType2_SV7_Proc * outputter_SV7_Process_out0 = outputter_SV7_Process_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV7_Process_out0) };

        try
        {
            // Init operator chain
            outputter_SV7_Process_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_14_Data0 row;
            outputter_SV7_Process_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV7_Process_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV7_Process_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
template ScopeProcessorManaged<Process_14_Data0, Process_14_Data0> * ScopeEngine::ScopeGrouperManagedFactory::Make<Process_14_Data0, Process_14_Data0, UID_Process_15>(OperatorDelegate<Process_14_Data0>*);
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV7_Process
#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)
#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV2_PROCESS) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV2_PROCESS) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV3_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV3_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV4_PROCESS) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV4_PROCESS) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV5_COMBINE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV5_COMBINE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV6_PROCESS) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)



#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV6_PROCESS) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV7_PROCESS) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)






#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV7_PROCESS) || defined(COMPILE_ALL_VERTICES)
// Empty footer
