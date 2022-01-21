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
#define UDO_ADAPTER_IMPORTS
#if defined(COMPILE_NATIVE)
#include "ScopeCommonError.h"
#include "ScopeError.h"
#include "ScopeOperators.h"
#include "UdoAdapterProxy.h"
#endif
#if defined(COMPILE_MANAGED)
#using <mscorlib.dll>
[assembly: System::Runtime::Versioning::TargetFrameworkAttribute(".NETFramework,Version=v4.7.2", FrameworkDisplayName = ".NET Framework, Version 4.7.2")];
#include "ScopeManaged.h"
#endif
#if defined(COMPILE_NATIVE)
#endif
using namespace ScopeEngine;
#if defined(COMPILE_NATIVE)
using namespace UdoAdapter;
#endif // defined(COMPILE_NATIVE)

static ScopeEngine::CompilerSettings GetCompilerSettings()
{
    static ScopeEngine::CompilerSettings settings;
    settings.m_enableWriteBehindCacheService = false;
    settings.m_abfsOutputBufferSizeMB = 24;
    settings.m_enableNullsInKeyRanges = false;
    settings.m_restrictOperatorMemorySpilling = false;
    settings.m_hashCombineMultiPartitionSpillingFlag = true;
    settings.m_storeType = ScopeEngine::StoreType::LocalStore;
    settings.m_verboseRuntimeStatistic = false;
    settings.m_vertexClassifyStoreError = true;
    return settings;
};
enum OperatorUID
{
    UID_GetSStream_0 = 1,
    UID_GetSStream_0_Data0 = 2,
    UID_SStreamOutput_1 = 3,
    UID_SV1_Extract_Split_out0 = 4,
    UID_SV1_Extract_Split_out1 = 5,
    UID_MetadataAggregate_2 = 6,
    UID_MetadataAggregate_2_Data0 = 7,
    UID_SStreamMetadataOutput_3 = 8,
    UID_SV2_Aggregate_out0 = 9,
    UID_Concatenate_5 = 10,
    UID_Extract_4 = 11,
    UID_SV3_Extract_out0 = 12,
    UID_GetSStream_5 = 13,
    UID_GetSStream_5_Data0 = 14,
    UID_GetSStream_6 = 15,
    UID_GetSStream_6_Data0 = 16,
    UID_Process_7 = 17,
    UID_Process_7_Data0 = 18,
    UID_HashJoin_8 = 19,
    UID_HashJoin_8_Data0 = 20,
    UID_Process_9 = 21,
    UID_SV12_Extract_Combine_out0 = 22,
    UID_HashJoin_10 = 23,
    UID_HashJoin_10_Data0 = 24,
    UID_Process_11 = 25,
    UID_Process_11_Data0 = 26,
    UID_Process_12 = 27,
    UID_Process_12_Data0 = 28,
    UID_SStreamOutput_13 = 29,
    UID_SV13_Combine_Split_out0 = 30,
    UID_SV13_Combine_Split_out1 = 31,
    UID_MetadataAggregate_14 = 32,
    UID_MetadataAggregate_14_Data0 = 33,
    UID_SStreamMetadataOutput_15 = 34,
    UID_SV14_Aggregate_out0 = 35,
    UID_Concatenate_19 = 36,
    UID_Extract_16 = 37,
    UID_Extract_16_Data0 = 38,
    UID_Split_17 = 39,
    UID_SV4_Extract_Split_out0 = 40,
    UID_SV4_Extract_Split_out1 = 41,
    UID_SV4_Extract_Split_out2 = 42,
    UID_SV4_Extract_Split_out3 = 43,
    UID_SV4_Extract_Split_out4 = 44,
    UID_MetadataAggregate_18 = 45,
    UID_MetadataAggregate_18_Data0 = 46,
    UID_SStreamMetadataOutput_19 = 47,
    UID_SV5_Aggregate_out0 = 48,
    UID_Concatenate_28 = 49,
    UID_Extract_20 = 50,
    UID_Extract_20_Data0 = 51,
    UID_Process_21 = 52,
    UID_Process_21_Data0 = 53,
    UID_Process_22 = 54,
    UID_Process_22_Data0 = 55,
    UID_Process_23 = 56,
    UID_Process_23_Data0 = 57,
    UID_SV6_Extract_out0 = 58,
    UID_Extract_25 = 59,
    UID_Extract_25_Data0 = 60,
    UID_SV7_Extract_out0 = 61,
    UID_Extract_27 = 62,
    UID_Extract_27_Data0 = 63,
    UID_Process_28 = 64,
    UID_Process_28_Data0 = 65,
    UID_Process_29 = 66,
    UID_Process_29_Data0 = 67,
    UID_SV8_Extract_out0 = 68,
    UID_Extract_31 = 69,
    UID_Extract_31_Data0 = 70,
    UID_SV9_Extract_out0 = 71,
    UID_Extract_33 = 72,
    UID_Extract_33_Data0 = 73,
    UID_SV10_Extract_out0 = 74,
    UID_Output_35 = 75,
    UID_Output_36 = 76,
    UID_Output_37 = 77,
    UID_Extract_38 = 78,
    UID_Extract_38_Data0 = 79,
    UID_Process_39 = 80,
    UID_Process_39_Data0 = 81,
    UID_SV11_Extract_out0 = 82,
    UID_Split_17_0 = 83,
    UID_Split_17_1 = 84,
    UID_Split_17_2 = 85,
    UID_Split_17_3 = 86,
    UID_Split_17_4 = 87,
    UID_HashJoin_8_0 = 88,
    UID_HashJoin_8_1 = 89,
    UID_HashJoin_10_0 = 90,
    UID_HashJoin_10_1 = 91,
    UID_HashJoin_8_FB_0 = 92,
    UID_HashJoin_8_FB_1 = 93,
    UID_HashJoin_10_FB_0 = 94,
    UID_HashJoin_10_FB_1 = 95,
    UID_Process_21_Prefix = 96,
    UID_Process_28_Prefix = 97,
    UID_ParallelUnionAll_Extract_4 = 98,
    UID_ParallelUnionAll_Extract_16 = 99,
    UID_ParallelUnionAll_Extract_20 = 100,
    UID_ParallelUnionAll_Extract_25 = 101,
    UID_ParallelUnionAll_Extract_27 = 102,
    UID_ParallelUnionAll_Extract_31 = 103,
    UID_ParallelUnionAll_Extract_33 = 104,
    UID_ParallelUnionAll_Extract_38 = 105
};

    // IDs representing UDTs to be used in native code
    enum UserDefinedTypeId
    {
        
    };

#if defined(COMPILE_MANAGED)
// Explicit instantiations for templated functions that are defined in managed code
#endif // defined(COMPILE_MANAGED)

#pragma region StructSchemas
#pragma endregion StructSchemas

#pragma region Schemas

    class Part_GetSStream_0
    {
    public:
        

        Part_GetSStream_0() = default;
        Part_GetSStream_0(const Part_GetSStream_0 & c, IncrementalAllocator * alloc);

        static string GetDefinition()
        {
            return std::string{};
        }

        friend std::ostream& operator<<(std::ostream& os, const Part_GetSStream_0& row)
        {

            return os;
        }
    };

    static_assert(sizeof(Part_GetSStream_0) == 1, "Incorrect size of row schema");

    class GetSStream_0_Data0
    {
    public:
        FString m_Column1;
        FString m_Column2;
        FString m_Column3;

        GetSStream_0_Data0() = default;
        GetSStream_0_Data0(const GetSStream_0_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const GetSStream_0_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Column1:string,Column2:string,Column3:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(GetSStream_0_Data0) == 48, "Incorrect size of row schema");

    class SV3_Extract_out0
    {
    public:
        int m_BingAdsUserId{};
        FString m_MsAlias;
        int m_UcmUserId{};

        SV3_Extract_out0() = default;
        SV3_Extract_out0(const SV3_Extract_out0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const SV3_Extract_out0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(SV3_Extract_out0) == 32, "Incorrect size of row schema");

    class Extract_16_Data0
    {
    public:
        int m_UserId{};
        ScopeDateTime m_Start;
        FString m_Region;
        FString m_Query;
        int m_Duration{};
        FString m_Urls;
        FString m_ClickedUrls;

        Extract_16_Data0() = default;
        Extract_16_Data0(const Extract_16_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_16_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"UserId:int,Start:DateTime,Region:string,Query:string,Duration:int,Urls:string,ClickedUrls:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_16_Data0) == 88, "Incorrect size of row schema");

    class Extract_20_Data0
    {
    public:
        FString m_Region;
        int m_Duration{};

        Extract_20_Data0() = default;
        Extract_20_Data0(const Extract_20_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_20_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Region:string,Duration:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_20_Data0) == 24, "Incorrect size of row schema");

    class Process_22_Data0
    {
    public:
        FString m_Region;
        int m_TotalDuration{};

        Process_22_Data0() = default;
        Process_22_Data0(const Process_22_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_22_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Region:string,TotalDuration:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_22_Data0) == 24, "Incorrect size of row schema");

    class Extract_25_Data0
    {
    public:
        int m_IId{};
        ScopeDateTime m_Start;
        FString m_Market;
        FString m_Query;
        int m_DwellTime{};
        FString m_Results;
        FString m_ClickedUrls;

        Extract_25_Data0() = default;
        Extract_25_Data0(const Extract_25_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_25_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"IId:int,Start:DateTime,Market:string,Query:string,DwellTime:int,Results:string,ClickedUrls:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_25_Data0) == 88, "Incorrect size of row schema");

    class Extract_27_Data0
    {
    public:
        double m_SepalLength{};
        double m_SepalWidth{};
        double m_PetalLength{};
        double m_PetalWidth{};
        FString m_Name;

        Extract_27_Data0() = default;
        Extract_27_Data0(const Extract_27_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_27_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"SepalLength:double,SepalWidth:double,PetalLength:double,PetalWidth:double,Name:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_27_Data0) == 48, "Incorrect size of row schema");

    class Process_29_Data0
    {
    public:
        double m_SepalLength_Mean{};
        double m_SepalWidth_Mean{};
        double m_PetalLength_Mean{};
        double m_PetalWidth_Mean{};
        FString m_Name;
        int m_Count{};

        Process_29_Data0() = default;
        Process_29_Data0(const Process_29_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_29_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"SepalLength_Mean:double,SepalWidth_Mean:double,PetalLength_Mean:double,PetalWidth_Mean:double,Name:string,Count:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_29_Data0) == 56, "Incorrect size of row schema");

    class ReduceKey_Process_29
    {
    public:
        FString m_Name;

        ReduceKey_Process_29() = default;
        ReduceKey_Process_29(const ReduceKey_Process_29 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const ReduceKey_Process_29& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Name:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(ReduceKey_Process_29) == 16, "Incorrect size of row schema");

    class Extract_31_Data0
    {
    public:
        FString m_UserId;
        FString m_Start;
        FString m_Region;
        FString m_Query;
        FString m_Duration;
        FString m_Urls;
        FString m_ClickedUrls;

        Extract_31_Data0() = default;
        Extract_31_Data0(const Extract_31_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_31_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"UserId:string,Start:string,Region:string,Query:string,Duration:string,Urls:string,ClickedUrls:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_31_Data0) == 112, "Incorrect size of row schema");

    class Extract_33_Data0
    {
    public:
        int m_Id{};
        ScopeDateTime m_Start;
        FString m_Market;
        FString m_Query;
        int m_DwellTime{};
        FString m_Results;
        FString m_ClickedUrls;

        Extract_33_Data0() = default;
        Extract_33_Data0(const Extract_33_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_33_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Id:int,Start:DateTime,Market:string,Query:string,DwellTime:int,Results:string,ClickedUrls:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_33_Data0) == 88, "Incorrect size of row schema");

    class Extract_38_Data0
    {
    public:
        ScopeDateTime m_Start;
        FString m_Market;
        int m_DwellTime{};

        Extract_38_Data0() = default;
        Extract_38_Data0(const Extract_38_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_38_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Start:DateTime,Market:string,DwellTime:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_38_Data0) == 32, "Incorrect size of row schema");

    class Process_39_Data0
    {
    public:
        ScopeDateTime m_Start;
        FString m_Market;
        double m_DwellTimeInMinutes{};

        Process_39_Data0() = default;
        Process_39_Data0(const Process_39_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_39_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Start:DateTime,Market:string,DwellTimeInMinutes:double" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_39_Data0) == 32, "Incorrect size of row schema");

    class GetSStream_6_Data0
    {
    public:
        int m_BingAdsUserId{};
        FString m_MsAlias;
        int m_UcmUserId{};
        int m_NumofWeek{};

        GetSStream_6_Data0() = default;
        GetSStream_6_Data0(const GetSStream_6_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const GetSStream_6_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int,NumofWeek:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(GetSStream_6_Data0) == 32, "Incorrect size of row schema");

    class Process_7_Data0
    {
    public:
        int m_NumofWeek{};
        int m_BingAdsUserId1{};
        FString m_MsAlias2;
        int m_UcmUserId3{};

        Process_7_Data0() = default;
        Process_7_Data0(const Process_7_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_7_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"NumofWeek:int,BingAdsUserId1:int,MsAlias2:string,UcmUserId3:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_7_Data0) == 32, "Incorrect size of row schema");

    class GetSStream_5_Data0
    {
    public:
        int m_BingAdsUserId{};
        FString m_MsAlias;
        int m_UcmUserId{};
        int m_NumofMonth{};
        FString m_LastMonth;
        int m_TotalUsage{};

        GetSStream_5_Data0() = default;
        GetSStream_5_Data0(const GetSStream_5_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const GetSStream_5_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int,NumofMonth:int,LastMonth:string,TotalUsage:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(GetSStream_5_Data0) == 56, "Incorrect size of row schema");

    class HashJoin_8_Data0
    {
    public:
        int m_BingAdsUserId{};
        FString m_MsAlias;
        int m_UcmUserId{};
        int m_NumofMonth{};
        FString m_LastMonth;
        int m_TotalUsage{};
        int m_NumofWeek{};

        HashJoin_8_Data0() = default;
        HashJoin_8_Data0(const HashJoin_8_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const HashJoin_8_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int,NumofMonth:int,LastMonth:string,TotalUsage:int,NumofWeek:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(HashJoin_8_Data0) == 56, "Incorrect size of row schema");

    class HashCmbnKey_HashJoin_8
    {
    public:
        int m_BingAdsUserId_BingAdsUserId1{};
        FString m_MsAlias_MsAlias2;
        int m_UcmUserId_UcmUserId3{};

        HashCmbnKey_HashJoin_8() = default;
        HashCmbnKey_HashJoin_8(const HashCmbnKey_HashJoin_8 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const HashCmbnKey_HashJoin_8& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"BingAdsUserId_BingAdsUserId1:int,MsAlias_MsAlias2:string,UcmUserId_UcmUserId3:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(HashCmbnKey_HashJoin_8) == 32, "Incorrect size of row schema");

    class HashCmbnVal_HashJoin_8
    {
    public:
        int m_NumofWeek{};

        HashCmbnVal_HashJoin_8() = default;
        HashCmbnVal_HashJoin_8(const HashCmbnVal_HashJoin_8 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const HashCmbnVal_HashJoin_8& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"NumofWeek:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(HashCmbnVal_HashJoin_8) == 4, "Incorrect size of row schema");

    class SV12_Extract_Combine_out0
    {
    public:
        int m_NumofMonth{};
        FString m_LastMonth;
        int m_TotalUsage{};
        int m_NumofWeek{};
        int m_BingAdsUserId1{};
        FString m_MsAlias2;
        int m_UcmUserId3{};

        SV12_Extract_Combine_out0() = default;
        SV12_Extract_Combine_out0(const SV12_Extract_Combine_out0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const SV12_Extract_Combine_out0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"NumofMonth:int,LastMonth:string,TotalUsage:int,NumofWeek:int,BingAdsUserId1:int,MsAlias2:string,UcmUserId3:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(SV12_Extract_Combine_out0) == 64, "Incorrect size of row schema");

    class HashJoin_10_Data0
    {
    public:
        int m_BingAdsUserId{};
        FString m_MsAlias;
        int m_UcmUserId{};
        NativeNullable<int> m_NumofMonth;
        FString m_LastMonth;
        NativeNullable<int> m_TotalUsage;
        NativeNullable<int> m_NumofWeek;

        HashJoin_10_Data0() = default;
        HashJoin_10_Data0(const HashJoin_10_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const HashJoin_10_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int,NumofMonth:int?,LastMonth:string,TotalUsage:int?,NumofWeek:int?" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(HashJoin_10_Data0) == 72, "Incorrect size of row schema");

    class HashCmbnVal_HashJoin_10
    {
    public:
        int m_NumofMonth{};
        FString m_LastMonth;
        int m_TotalUsage{};
        int m_NumofWeek{};

        HashCmbnVal_HashJoin_10() = default;
        HashCmbnVal_HashJoin_10(const HashCmbnVal_HashJoin_10 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const HashCmbnVal_HashJoin_10& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"NumofMonth:int,LastMonth:string,TotalUsage:int,NumofWeek:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(HashCmbnVal_HashJoin_10) == 32, "Incorrect size of row schema");

    class Process_11_Data0
    {
    public:
        int m_BingAdsUserId{};
        FString m_MsAlias;
        int m_UcmUserId{};
        int m_NumofMonth{};
        FString m_LastMonth;
        int m_NumofWeek{};
        int m_TotalUsage{};

        Process_11_Data0() = default;
        Process_11_Data0(const Process_11_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_11_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int,NumofMonth:int,LastMonth:string,NumofWeek:int,TotalUsage:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_11_Data0) == 56, "Incorrect size of row schema");

    class Process_12_Data0
    {
    public:
        int m_BingAdsUserId{};
        FString m_MsAlias;
        int m_UcmUserId{};
        FString m_FreqSegment;
        int m_NumofMonth{};
        FString m_LastMonth;
        int m_NumofWeek{};
        int m_TotalUsage{};

        Process_12_Data0() = default;
        Process_12_Data0(const Process_12_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_12_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int,FreqSegment:string,NumofMonth:int,LastMonth:string,NumofWeek:int,TotalUsage:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_12_Data0) == 80, "Incorrect size of row schema");
#pragma endregion Schemas

#if defined(COMPILE_MANAGED)
#pragma region ManagedRows
    template<>
    struct ManagedRow<Process_22_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_Region_String_TotalDuration_Integer Row;

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
    struct ManagedRow<Extract_25_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_42AAB829FBD45C8D Row;

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
    struct ManagedRow<Extract_38_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_Start_DateTime_Market_String_DwellTime_Integer Row;

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
    struct ManagedRow<Process_39_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_Start_DateTime_Market_String_DwellTimeInMinutes_Double Row;

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
    struct ManagedRow<Process_11_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_2AA7BDBB31C1E23B Row;

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
    struct ManagedRow<Process_12_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_BA9089D6CEAA8BB5 Row;

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
#pragma endregion ManagedRows

#pragma region ManagedUDTs
#pragma endregion ManagedUDTs
#endif // defined(COMPILE_MANAGED)


#pragma region AdapterRowPolicies
#if defined(COMPILE_NATIVE)
    template<>
    class ProxyHostRowPolicy<Extract_27_Data0>
    {
    public:
        ColumnAccessData m_accessData[5];
        ProxyHostColumnMeta m_columns[5];
        std::map<const char*, int, CStringCompare> m_columnMap;

        ProxyHostRowPolicy(): ProxyHostRowPolicy(std::vector<columnIndex_t>()) {}

        ProxyHostRowPolicy(const std::vector<columnIndex_t>& readOnlyColumns)
        {
            bool isReadOnlyColumn[5];
            std::fill(isReadOnlyColumn, isReadOnlyColumn + 5, false);
            for(auto& index : readOnlyColumns)
            {
                isReadOnlyColumn[index] = true;
            }

            m_accessData[0].Initialize(true, offsetof(Extract_27_Data0, m_SepalLength), sizeof(decltype(Extract_27_Data0::m_SepalLength)));
            m_columns[0].Initialize("SepalLength", USqlColumnType::Double, isReadOnlyColumn[0]);
            m_columnMap.insert(make_pair("SepalLength", 0));
            m_accessData[1].Initialize(true, offsetof(Extract_27_Data0, m_SepalWidth), sizeof(decltype(Extract_27_Data0::m_SepalWidth)));
            m_columns[1].Initialize("SepalWidth", USqlColumnType::Double, isReadOnlyColumn[1]);
            m_columnMap.insert(make_pair("SepalWidth", 1));
            m_accessData[2].Initialize(true, offsetof(Extract_27_Data0, m_PetalLength), sizeof(decltype(Extract_27_Data0::m_PetalLength)));
            m_columns[2].Initialize("PetalLength", USqlColumnType::Double, isReadOnlyColumn[2]);
            m_columnMap.insert(make_pair("PetalLength", 2));
            m_accessData[3].Initialize(true, offsetof(Extract_27_Data0, m_PetalWidth), sizeof(decltype(Extract_27_Data0::m_PetalWidth)));
            m_columns[3].Initialize("PetalWidth", USqlColumnType::Double, isReadOnlyColumn[3]);
            m_columnMap.insert(make_pair("PetalWidth", 3));
            m_accessData[4].Initialize(false, offsetof(Extract_27_Data0, m_Name), sizeof(decltype(Extract_27_Data0::m_Name)));
            m_columns[4].Initialize("Name", USqlColumnType::String, isReadOnlyColumn[4]);
            m_columnMap.insert(make_pair("Name", 4));
        }

        columnIndex_t GetColumnCount() const noexcept
        {
            return 5;
        }

        void GetFixedLengthColumn(columnIndex_t index, FixedLengthColumnData& columnData, const Extract_27_Data0& row) const
        {
            if (index >= 5)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 5});
            if (!m_accessData[index].m_fixedLength)
                throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Variable length", "GetFixedLengthColumn"});

            switch (index)
            {
                case 0: case 1: case 2: case 3: // double
                {
                    double* data = reinterpret_cast<double*>((char*)(&row) + m_accessData[index].m_offset);
                    columnData.SetNonNullValue<double>(USqlColumnType::Double, *data);
                    break;
                }
            default:
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }

        void GetVariableLengthColumn(columnIndex_t index, IColumnDataWriter& columnData, const Extract_27_Data0& row) const
        {
            if (index >= 5)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 5});
            if (m_accessData[index].m_fixedLength)
            throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Fixed length", "GetVariableLengthColumn"});

            switch (index)
            {
                case 4: // FString
                {
                    FString *data = reinterpret_cast<FString*>((char*)(&row) + m_accessData[index].m_offset);
                    if (data->IsNull())
                        columnData.Nullify(USqlColumnType::String);
                    else
                        columnData.SetData(USqlColumnType::String, (const char*)data->buffer(), data->size());
                     break;
                }

            default: 
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }
    };
#endif // defined(COMPILE_NATIVE)
#if defined(COMPILE_NATIVE)
    template<>
    class ProxyHostRowPolicy<Process_29_Data0>
    {
    public:
        ColumnAccessData m_accessData[6];
        ProxyHostColumnMeta m_columns[6];
        std::map<const char*, int, CStringCompare> m_columnMap;

        ProxyHostRowPolicy(): ProxyHostRowPolicy(std::vector<columnIndex_t>()) {}

        ProxyHostRowPolicy(const std::vector<columnIndex_t>& readOnlyColumns)
        {
            bool isReadOnlyColumn[6];
            std::fill(isReadOnlyColumn, isReadOnlyColumn + 6, false);
            for(auto& index : readOnlyColumns)
            {
                isReadOnlyColumn[index] = true;
            }

            m_accessData[0].Initialize(true, offsetof(Process_29_Data0, m_SepalLength_Mean), sizeof(decltype(Process_29_Data0::m_SepalLength_Mean)));
            m_columns[0].Initialize("SepalLength_Mean", USqlColumnType::Double, isReadOnlyColumn[0]);
            m_columnMap.insert(make_pair("SepalLength_Mean", 0));
            m_accessData[1].Initialize(true, offsetof(Process_29_Data0, m_SepalWidth_Mean), sizeof(decltype(Process_29_Data0::m_SepalWidth_Mean)));
            m_columns[1].Initialize("SepalWidth_Mean", USqlColumnType::Double, isReadOnlyColumn[1]);
            m_columnMap.insert(make_pair("SepalWidth_Mean", 1));
            m_accessData[2].Initialize(true, offsetof(Process_29_Data0, m_PetalLength_Mean), sizeof(decltype(Process_29_Data0::m_PetalLength_Mean)));
            m_columns[2].Initialize("PetalLength_Mean", USqlColumnType::Double, isReadOnlyColumn[2]);
            m_columnMap.insert(make_pair("PetalLength_Mean", 2));
            m_accessData[3].Initialize(true, offsetof(Process_29_Data0, m_PetalWidth_Mean), sizeof(decltype(Process_29_Data0::m_PetalWidth_Mean)));
            m_columns[3].Initialize("PetalWidth_Mean", USqlColumnType::Double, isReadOnlyColumn[3]);
            m_columnMap.insert(make_pair("PetalWidth_Mean", 3));
            m_accessData[4].Initialize(false, offsetof(Process_29_Data0, m_Name), sizeof(decltype(Process_29_Data0::m_Name)));
            m_columns[4].Initialize("Name", USqlColumnType::String, isReadOnlyColumn[4]);
            m_columnMap.insert(make_pair("Name", 4));
            m_accessData[5].Initialize(true, offsetof(Process_29_Data0, m_Count), sizeof(decltype(Process_29_Data0::m_Count)));
            m_columns[5].Initialize("Count", USqlColumnType::Integer, isReadOnlyColumn[5]);
            m_columnMap.insert(make_pair("Count", 5));
        }

        columnIndex_t GetColumnCount() const noexcept
        {
            return 6;
        }

        void GetFixedLengthColumn(columnIndex_t index, FixedLengthColumnData& columnData, const Process_29_Data0& row) const
        {
            if (index >= 6)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 6});
            if (!m_accessData[index].m_fixedLength)
                throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Variable length", "GetFixedLengthColumn"});

            switch (index)
            {
                case 5: // int
                {
                    int* data = reinterpret_cast<int*>((char*)(&row) + m_accessData[index].m_offset);
                    columnData.SetNonNullValue<int>(USqlColumnType::Integer, *data);
                    break;
                }
                case 0: case 1: case 2: case 3: // double
                {
                    double* data = reinterpret_cast<double*>((char*)(&row) + m_accessData[index].m_offset);
                    columnData.SetNonNullValue<double>(USqlColumnType::Double, *data);
                    break;
                }
            default:
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }

        void GetVariableLengthColumn(columnIndex_t index, IColumnDataWriter& columnData, const Process_29_Data0& row) const
        {
            if (index >= 6)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 6});
            if (m_accessData[index].m_fixedLength)
            throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Fixed length", "GetVariableLengthColumn"});

            switch (index)
            {
                case 4: // FString
                {
                    FString *data = reinterpret_cast<FString*>((char*)(&row) + m_accessData[index].m_offset);
                    if (data->IsNull())
                        columnData.Nullify(USqlColumnType::String);
                    else
                        columnData.SetData(USqlColumnType::String, (const char*)data->buffer(), data->size());
                     break;
                }

            default: 
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }
    };
#endif // defined(COMPILE_NATIVE)
#if defined(COMPILE_NATIVE)
    template<>
    class ProxyHostRowPolicy<ReduceKey_Process_29>
    {
    public:
        ColumnAccessData m_accessData[1];
        ProxyHostColumnMeta m_columns[1];
        std::map<const char*, int, CStringCompare> m_columnMap;

        ProxyHostRowPolicy(): ProxyHostRowPolicy(std::vector<columnIndex_t>()) {}

        ProxyHostRowPolicy(const std::vector<columnIndex_t>& readOnlyColumns)
        {
            bool isReadOnlyColumn[1];
            std::fill(isReadOnlyColumn, isReadOnlyColumn + 1, false);
            for(auto& index : readOnlyColumns)
            {
                isReadOnlyColumn[index] = true;
            }

            m_accessData[0].Initialize(false, offsetof(ReduceKey_Process_29, m_Name), sizeof(decltype(ReduceKey_Process_29::m_Name)));
            m_columns[0].Initialize("Name", USqlColumnType::String, isReadOnlyColumn[0]);
            m_columnMap.insert(make_pair("Name", 0));
        }

        columnIndex_t GetColumnCount() const noexcept
        {
            return 1;
        }

        void GetFixedLengthColumn(columnIndex_t index, FixedLengthColumnData& columnData, const ReduceKey_Process_29& row) const
        {
            if (index >= 1)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 1});
            if (!m_accessData[index].m_fixedLength)
                throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Variable length", "GetFixedLengthColumn"});
        }

        void GetVariableLengthColumn(columnIndex_t index, IColumnDataWriter& columnData, const ReduceKey_Process_29& row) const
        {
            if (index >= 1)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 1});
            if (m_accessData[index].m_fixedLength)
            throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Fixed length", "GetVariableLengthColumn"});

            switch (index)
            {
                case 0: // FString
                {
                    FString *data = reinterpret_cast<FString*>((char*)(&row) + m_accessData[index].m_offset);
                    if (data->IsNull())
                        columnData.Nullify(USqlColumnType::String);
                    else
                        columnData.SetData(USqlColumnType::String, (const char*)data->buffer(), data->size());
                     break;
                }

            default: 
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }
    };
#endif // defined(COMPILE_NATIVE)
#if defined(COMPILE_NATIVE)
    template<>
    class ProxyHostRowPolicy<Extract_31_Data0>
    {
    public:
        ColumnAccessData m_accessData[7];
        ProxyHostColumnMeta m_columns[7];
        std::map<const char*, int, CStringCompare> m_columnMap;

        ProxyHostRowPolicy(): ProxyHostRowPolicy(std::vector<columnIndex_t>()) {}

        ProxyHostRowPolicy(const std::vector<columnIndex_t>& readOnlyColumns)
        {
            bool isReadOnlyColumn[7];
            std::fill(isReadOnlyColumn, isReadOnlyColumn + 7, false);
            for(auto& index : readOnlyColumns)
            {
                isReadOnlyColumn[index] = true;
            }

            m_accessData[0].Initialize(false, offsetof(Extract_31_Data0, m_UserId), sizeof(decltype(Extract_31_Data0::m_UserId)));
            m_columns[0].Initialize("UserId", USqlColumnType::String, isReadOnlyColumn[0]);
            m_columnMap.insert(make_pair("UserId", 0));
            m_accessData[1].Initialize(false, offsetof(Extract_31_Data0, m_Start), sizeof(decltype(Extract_31_Data0::m_Start)));
            m_columns[1].Initialize("Start", USqlColumnType::String, isReadOnlyColumn[1]);
            m_columnMap.insert(make_pair("Start", 1));
            m_accessData[2].Initialize(false, offsetof(Extract_31_Data0, m_Region), sizeof(decltype(Extract_31_Data0::m_Region)));
            m_columns[2].Initialize("Region", USqlColumnType::String, isReadOnlyColumn[2]);
            m_columnMap.insert(make_pair("Region", 2));
            m_accessData[3].Initialize(false, offsetof(Extract_31_Data0, m_Query), sizeof(decltype(Extract_31_Data0::m_Query)));
            m_columns[3].Initialize("Query", USqlColumnType::String, isReadOnlyColumn[3]);
            m_columnMap.insert(make_pair("Query", 3));
            m_accessData[4].Initialize(false, offsetof(Extract_31_Data0, m_Duration), sizeof(decltype(Extract_31_Data0::m_Duration)));
            m_columns[4].Initialize("Duration", USqlColumnType::String, isReadOnlyColumn[4]);
            m_columnMap.insert(make_pair("Duration", 4));
            m_accessData[5].Initialize(false, offsetof(Extract_31_Data0, m_Urls), sizeof(decltype(Extract_31_Data0::m_Urls)));
            m_columns[5].Initialize("Urls", USqlColumnType::String, isReadOnlyColumn[5]);
            m_columnMap.insert(make_pair("Urls", 5));
            m_accessData[6].Initialize(false, offsetof(Extract_31_Data0, m_ClickedUrls), sizeof(decltype(Extract_31_Data0::m_ClickedUrls)));
            m_columns[6].Initialize("ClickedUrls", USqlColumnType::String, isReadOnlyColumn[6]);
            m_columnMap.insert(make_pair("ClickedUrls", 6));
        }

        columnIndex_t GetColumnCount() const noexcept
        {
            return 7;
        }

        void GetFixedLengthColumn(columnIndex_t index, FixedLengthColumnData& columnData, const Extract_31_Data0& row) const
        {
            if (index >= 7)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 7});
            if (!m_accessData[index].m_fixedLength)
                throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Variable length", "GetFixedLengthColumn"});
        }

        void GetVariableLengthColumn(columnIndex_t index, IColumnDataWriter& columnData, const Extract_31_Data0& row) const
        {
            if (index >= 7)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 7});
            if (m_accessData[index].m_fixedLength)
            throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Fixed length", "GetVariableLengthColumn"});

            switch (index)
            {
                case 0: case 1: case 2: case 3: case 4: case 5: case 6: // FString
                {
                    FString *data = reinterpret_cast<FString*>((char*)(&row) + m_accessData[index].m_offset);
                    if (data->IsNull())
                        columnData.Nullify(USqlColumnType::String);
                    else
                        columnData.SetData(USqlColumnType::String, (const char*)data->buffer(), data->size());
                     break;
                }

            default: 
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }
    };
#endif // defined(COMPILE_NATIVE)
#pragma endregion AdapterRowPolicies

#pragma region BinaryPolicies


#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Part_GetSStream_0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Part_GetSStream_0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
        static bool DeserializeKeyForSS(MemoryInputStream * input, Part_GetSStream_0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
        static void DeserializeKey(ResourceInputStream * input, Part_GetSStream_0 & row)
        {
            char type = 0, null = 0;
        }
        static void DeserializePartitionSpec(ResourceInputStream * input, Part_GetSStream_0 & row)
        {
            return ;
        }

    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<Part_GetSStream_0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Part_GetSStream_0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            output->Write(b);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Part_GetSStream_0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
        static void SerializeKeyForSS(MemoryOutputStream* output, const Part_GetSStream_0 & row)
        {
            output->Write(false);
        }
    };



    template<typename StreamSchemaType>
    class KeyRangeOutputPolicy<Part_GetSStream_0, StreamSchemaType>
    {
    public:
        static void Serialize(MemoryOutputStream* output, const Part_GetSStream_0 & row, bool isFinal = false)
        {
            output->Write(false);
        }
    };


#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<GetSStream_0_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, GetSStream_0_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Column1);
                    input->Read(row.m_Column2);
                    input->Read(row.m_Column3);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Column1);
                    }
                    else
                    {
                        row.m_Column1.SetNull();
                    }
                    if ((___masking___[0] & 4 ) != 4)
                    {
                        input->Read(row.m_Column2);
                    }
                    else
                    {
                        row.m_Column2.SetNull();
                    }
                    if ((___masking___[0] & 8 ) != 8)
                    {
                        input->Read(row.m_Column3);
                    }
                    else
                    {
                        row.m_Column3.SetNull();
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
    class BinaryOutputPolicy<GetSStream_0_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, GetSStream_0_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Column1.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (row.m_Column2.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 4;
            }
            if (row.m_Column3.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 8;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            if (!row.m_Column1.IsNull())
            {
                output->Write(row.m_Column1);
            }
            if (!row.m_Column2.IsNull())
            {
                output->Write(row.m_Column2);
            }
            if (!row.m_Column3.IsNull())
            {
                output->Write(row.m_Column3);
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
        static void Serialize(DummyOutputStream * output, const GetSStream_0_Data0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const GetSStream_0_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<SV3_Extract_out0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, SV3_Extract_out0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_BingAdsUserId);
                    input->Read(row.m_MsAlias);
                    input->Read(row.m_UcmUserId);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_BingAdsUserId);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_MsAlias);
                    }
                    else
                    {
                        row.m_MsAlias.SetNull();
                    }
                    input->Read(row.m_UcmUserId);
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
    class BinaryOutputPolicy<SV3_Extract_out0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, SV3_Extract_out0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_MsAlias.IsNull())
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
            output->Write(row.m_BingAdsUserId);
            if (!row.m_MsAlias.IsNull())
            {
                output->Write(row.m_MsAlias);
            }
            output->Write(row.m_UcmUserId);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const SV3_Extract_out0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const SV3_Extract_out0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Extract_16_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Extract_16_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_UserId);
                    input->Read(row.m_Start);
                    input->Read(row.m_Region);
                    input->Read(row.m_Query);
                    input->Read(row.m_Duration);
                    input->Read(row.m_Urls);
                    input->Read(row.m_ClickedUrls);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_UserId);
                    input->Read(row.m_Start);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Region);
                    }
                    else
                    {
                        row.m_Region.SetNull();
                    }
                    if ((___masking___[0] & 4 ) != 4)
                    {
                        input->Read(row.m_Query);
                    }
                    else
                    {
                        row.m_Query.SetNull();
                    }
                    input->Read(row.m_Duration);
                    if ((___masking___[0] & 8 ) != 8)
                    {
                        input->Read(row.m_Urls);
                    }
                    else
                    {
                        row.m_Urls.SetNull();
                    }
                    if ((___masking___[0] & 16 ) != 16)
                    {
                        input->Read(row.m_ClickedUrls);
                    }
                    else
                    {
                        row.m_ClickedUrls.SetNull();
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
    class BinaryOutputPolicy<Extract_16_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Extract_16_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Region.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (row.m_Query.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 4;
            }
            if (row.m_Urls.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 8;
            }
            if (row.m_ClickedUrls.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 16;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            output->Write(row.m_UserId);
            output->Write(row.m_Start);
            if (!row.m_Region.IsNull())
            {
                output->Write(row.m_Region);
            }
            if (!row.m_Query.IsNull())
            {
                output->Write(row.m_Query);
            }
            output->Write(row.m_Duration);
            if (!row.m_Urls.IsNull())
            {
                output->Write(row.m_Urls);
            }
            if (!row.m_ClickedUrls.IsNull())
            {
                output->Write(row.m_ClickedUrls);
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
        static void Serialize(DummyOutputStream * output, const Extract_16_Data0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Extract_16_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Extract_20_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Extract_20_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Region);
                    input->Read(row.m_Duration);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Region);
                    }
                    else
                    {
                        row.m_Region.SetNull();
                    }
                    input->Read(row.m_Duration);
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
    class BinaryOutputPolicy<Extract_20_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Extract_20_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Region.IsNull())
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
            if (!row.m_Region.IsNull())
            {
                output->Write(row.m_Region);
            }
            output->Write(row.m_Duration);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Extract_20_Data0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Extract_20_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Extract_27_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Extract_27_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_SepalLength);
                    input->Read(row.m_SepalWidth);
                    input->Read(row.m_PetalLength);
                    input->Read(row.m_PetalWidth);
                    input->Read(row.m_Name);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_SepalLength);
                    input->Read(row.m_SepalWidth);
                    input->Read(row.m_PetalLength);
                    input->Read(row.m_PetalWidth);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Name);
                    }
                    else
                    {
                        row.m_Name.SetNull();
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
    class BinaryOutputPolicy<Extract_27_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Extract_27_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Name.IsNull())
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
            output->Write(row.m_SepalLength);
            output->Write(row.m_SepalWidth);
            output->Write(row.m_PetalLength);
            output->Write(row.m_PetalWidth);
            if (!row.m_Name.IsNull())
            {
                output->Write(row.m_Name);
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
        static void Serialize(DummyOutputStream * output, const Extract_27_Data0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Extract_27_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<SV12_Extract_Combine_out0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, SV12_Extract_Combine_out0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_NumofMonth);
                    input->Read(row.m_LastMonth);
                    input->Read(row.m_TotalUsage);
                    input->Read(row.m_NumofWeek);
                    input->Read(row.m_BingAdsUserId1);
                    input->Read(row.m_MsAlias2);
                    input->Read(row.m_UcmUserId3);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_NumofMonth);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_LastMonth);
                    }
                    else
                    {
                        row.m_LastMonth.SetNull();
                    }
                    input->Read(row.m_TotalUsage);
                    input->Read(row.m_NumofWeek);
                    input->Read(row.m_BingAdsUserId1);
                    if ((___masking___[0] & 4 ) != 4)
                    {
                        input->Read(row.m_MsAlias2);
                    }
                    else
                    {
                        row.m_MsAlias2.SetNull();
                    }
                    input->Read(row.m_UcmUserId3);
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
    class BinaryOutputPolicy<SV12_Extract_Combine_out0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, SV12_Extract_Combine_out0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_LastMonth.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (row.m_MsAlias2.IsNull())
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
            output->Write(row.m_NumofMonth);
            if (!row.m_LastMonth.IsNull())
            {
                output->Write(row.m_LastMonth);
            }
            output->Write(row.m_TotalUsage);
            output->Write(row.m_NumofWeek);
            output->Write(row.m_BingAdsUserId1);
            if (!row.m_MsAlias2.IsNull())
            {
                output->Write(row.m_MsAlias2);
            }
            output->Write(row.m_UcmUserId3);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const SV12_Extract_Combine_out0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const SV12_Extract_Combine_out0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<GetSStream_5_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, GetSStream_5_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_BingAdsUserId);
                    input->Read(row.m_MsAlias);
                    input->Read(row.m_UcmUserId);
                    input->Read(row.m_NumofMonth);
                    input->Read(row.m_LastMonth);
                    input->Read(row.m_TotalUsage);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_BingAdsUserId);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_MsAlias);
                    }
                    else
                    {
                        row.m_MsAlias.SetNull();
                    }
                    input->Read(row.m_UcmUserId);
                    input->Read(row.m_NumofMonth);
                    if ((___masking___[0] & 4 ) != 4)
                    {
                        input->Read(row.m_LastMonth);
                    }
                    else
                    {
                        row.m_LastMonth.SetNull();
                    }
                    input->Read(row.m_TotalUsage);
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
    class BinaryOutputPolicy<GetSStream_5_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, GetSStream_5_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_MsAlias.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (row.m_LastMonth.IsNull())
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
            output->Write(row.m_BingAdsUserId);
            if (!row.m_MsAlias.IsNull())
            {
                output->Write(row.m_MsAlias);
            }
            output->Write(row.m_UcmUserId);
            output->Write(row.m_NumofMonth);
            if (!row.m_LastMonth.IsNull())
            {
                output->Write(row.m_LastMonth);
            }
            output->Write(row.m_TotalUsage);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const GetSStream_5_Data0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const GetSStream_5_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Process_7_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Process_7_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_NumofWeek);
                    input->Read(row.m_BingAdsUserId1);
                    input->Read(row.m_MsAlias2);
                    input->Read(row.m_UcmUserId3);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_NumofWeek);
                    input->Read(row.m_BingAdsUserId1);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_MsAlias2);
                    }
                    else
                    {
                        row.m_MsAlias2.SetNull();
                    }
                    input->Read(row.m_UcmUserId3);
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
    class BinaryOutputPolicy<Process_7_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Process_7_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_MsAlias2.IsNull())
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
            output->Write(row.m_NumofWeek);
            output->Write(row.m_BingAdsUserId1);
            if (!row.m_MsAlias2.IsNull())
            {
                output->Write(row.m_MsAlias2);
            }
            output->Write(row.m_UcmUserId3);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Process_7_Data0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Process_7_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Process_12_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Process_12_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_BingAdsUserId);
                    input->Read(row.m_MsAlias);
                    input->Read(row.m_UcmUserId);
                    input->Read(row.m_FreqSegment);
                    input->Read(row.m_NumofMonth);
                    input->Read(row.m_LastMonth);
                    input->Read(row.m_NumofWeek);
                    input->Read(row.m_TotalUsage);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_BingAdsUserId);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_MsAlias);
                    }
                    else
                    {
                        row.m_MsAlias.SetNull();
                    }
                    input->Read(row.m_UcmUserId);
                    if ((___masking___[0] & 4 ) != 4)
                    {
                        input->Read(row.m_FreqSegment);
                    }
                    else
                    {
                        row.m_FreqSegment.SetNull();
                    }
                    input->Read(row.m_NumofMonth);
                    if ((___masking___[0] & 8 ) != 8)
                    {
                        input->Read(row.m_LastMonth);
                    }
                    else
                    {
                        row.m_LastMonth.SetNull();
                    }
                    input->Read(row.m_NumofWeek);
                    input->Read(row.m_TotalUsage);
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
    class BinaryOutputPolicy<Process_12_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Process_12_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_MsAlias.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (row.m_FreqSegment.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 4;
            }
            if (row.m_LastMonth.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 8;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            output->Write(row.m_BingAdsUserId);
            if (!row.m_MsAlias.IsNull())
            {
                output->Write(row.m_MsAlias);
            }
            output->Write(row.m_UcmUserId);
            if (!row.m_FreqSegment.IsNull())
            {
                output->Write(row.m_FreqSegment);
            }
            output->Write(row.m_NumofMonth);
            if (!row.m_LastMonth.IsNull())
            {
                output->Write(row.m_LastMonth);
            }
            output->Write(row.m_NumofWeek);
            output->Write(row.m_TotalUsage);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Process_12_Data0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Process_12_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };

#pragma endregion BinaryPolicies
#pragma region IntermediateSStreamExtractPolicies
#pragma endregion IntermediateSStreamExtractPolicies
#pragma region Schema Constructors
    INLINE Part_GetSStream_0::Part_GetSStream_0(const Part_GetSStream_0 & c, IncrementalAllocator * alloc)
    {
    }


    INLINE SV3_Extract_out0::SV3_Extract_out0(const SV3_Extract_out0 & c, IncrementalAllocator * alloc) :
            m_BingAdsUserId(c.m_BingAdsUserId),
            m_MsAlias(c.m_MsAlias, alloc),
            m_UcmUserId(c.m_UcmUserId)
    {
    }

    INLINE Extract_16_Data0::Extract_16_Data0(const Extract_16_Data0 & c, IncrementalAllocator * alloc) :
            m_UserId(c.m_UserId),
            m_Start(c.m_Start),
            m_Region(c.m_Region, alloc),
            m_Query(c.m_Query, alloc),
            m_Duration(c.m_Duration),
            m_Urls(c.m_Urls, alloc),
            m_ClickedUrls(c.m_ClickedUrls, alloc)
    {
    }

    INLINE Extract_20_Data0::Extract_20_Data0(const Extract_20_Data0 & c, IncrementalAllocator * alloc) :
            m_Region(c.m_Region, alloc),
            m_Duration(c.m_Duration)
    {
    }


    INLINE Extract_25_Data0::Extract_25_Data0(const Extract_25_Data0 & c, IncrementalAllocator * alloc) :
            m_IId(c.m_IId),
            m_Start(c.m_Start),
            m_Market(c.m_Market, alloc),
            m_Query(c.m_Query, alloc),
            m_DwellTime(c.m_DwellTime),
            m_Results(c.m_Results, alloc),
            m_ClickedUrls(c.m_ClickedUrls, alloc)
    {
    }

    INLINE Extract_27_Data0::Extract_27_Data0(const Extract_27_Data0 & c, IncrementalAllocator * alloc) :
            m_SepalLength(c.m_SepalLength),
            m_SepalWidth(c.m_SepalWidth),
            m_PetalLength(c.m_PetalLength),
            m_PetalWidth(c.m_PetalWidth),
            m_Name(c.m_Name, alloc)
    {
    }



    INLINE Extract_31_Data0::Extract_31_Data0(const Extract_31_Data0 & c, IncrementalAllocator * alloc) :
            m_UserId(c.m_UserId, alloc),
            m_Start(c.m_Start, alloc),
            m_Region(c.m_Region, alloc),
            m_Query(c.m_Query, alloc),
            m_Duration(c.m_Duration, alloc),
            m_Urls(c.m_Urls, alloc),
            m_ClickedUrls(c.m_ClickedUrls, alloc)
    {
    }

    INLINE Extract_33_Data0::Extract_33_Data0(const Extract_33_Data0 & c, IncrementalAllocator * alloc) :
            m_Id(c.m_Id),
            m_Start(c.m_Start),
            m_Market(c.m_Market, alloc),
            m_Query(c.m_Query, alloc),
            m_DwellTime(c.m_DwellTime),
            m_Results(c.m_Results, alloc),
            m_ClickedUrls(c.m_ClickedUrls, alloc)
    {
    }

    INLINE Extract_38_Data0::Extract_38_Data0(const Extract_38_Data0 & c, IncrementalAllocator * alloc) :
            m_Start(c.m_Start),
            m_Market(c.m_Market, alloc),
            m_DwellTime(c.m_DwellTime)
    {
    }



    INLINE Process_7_Data0::Process_7_Data0(const Process_7_Data0 & c, IncrementalAllocator * alloc) :
            m_NumofWeek(c.m_NumofWeek),
            m_BingAdsUserId1(c.m_BingAdsUserId1),
            m_MsAlias2(c.m_MsAlias2, alloc),
            m_UcmUserId3(c.m_UcmUserId3)
    {
    }

    INLINE GetSStream_5_Data0::GetSStream_5_Data0(const GetSStream_5_Data0 & c, IncrementalAllocator * alloc) :
            m_BingAdsUserId(c.m_BingAdsUserId),
            m_MsAlias(c.m_MsAlias, alloc),
            m_UcmUserId(c.m_UcmUserId),
            m_NumofMonth(c.m_NumofMonth),
            m_LastMonth(c.m_LastMonth, alloc),
            m_TotalUsage(c.m_TotalUsage)
    {
    }


    INLINE HashCmbnKey_HashJoin_8::HashCmbnKey_HashJoin_8(const HashCmbnKey_HashJoin_8 & c, IncrementalAllocator * alloc) :
            m_BingAdsUserId_BingAdsUserId1(c.m_BingAdsUserId_BingAdsUserId1),
            m_MsAlias_MsAlias2(c.m_MsAlias_MsAlias2, alloc),
            m_UcmUserId_UcmUserId3(c.m_UcmUserId_UcmUserId3)
    {
    }

    INLINE HashCmbnVal_HashJoin_8::HashCmbnVal_HashJoin_8(const HashCmbnVal_HashJoin_8 & c, IncrementalAllocator * alloc) :
            m_NumofWeek(c.m_NumofWeek)
    {
    }

    INLINE SV12_Extract_Combine_out0::SV12_Extract_Combine_out0(const SV12_Extract_Combine_out0 & c, IncrementalAllocator * alloc) :
            m_NumofMonth(c.m_NumofMonth),
            m_LastMonth(c.m_LastMonth, alloc),
            m_TotalUsage(c.m_TotalUsage),
            m_NumofWeek(c.m_NumofWeek),
            m_BingAdsUserId1(c.m_BingAdsUserId1),
            m_MsAlias2(c.m_MsAlias2, alloc),
            m_UcmUserId3(c.m_UcmUserId3)
    {
    }


    INLINE HashCmbnVal_HashJoin_10::HashCmbnVal_HashJoin_10(const HashCmbnVal_HashJoin_10 & c, IncrementalAllocator * alloc) :
            m_NumofMonth(c.m_NumofMonth),
            m_LastMonth(c.m_LastMonth, alloc),
            m_TotalUsage(c.m_TotalUsage),
            m_NumofWeek(c.m_NumofWeek)
    {
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


ScopeEngine::ProxyHostEnvironmentHelper* g_udoAdapterHostEnvironment = NULL;

extern "C" __declspec(dllexport) const int StoreAccessMode{ 0 };

extern "C" __declspec(dllexport) void __stdcall InitVertexNative(VertexExecutionInfo * vertexExecutionInfo)
{
#if defined(FORCEMANAGEDDATETIMESER)
    ScopeEngine::ScopeDateTime::ForceManagedSerialization = true;
#endif

    ErrorManager::GetGlobal()->EnableJSON();
    ErrorManager::GetGlobal()->EnableRowDump(true);
}

// Add broadcast vertex code
extern "C" __declspec(dllexport) void __stdcall SV_CopyThrough_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
{
    ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
    if (inputCnt != 1 || outputCnt != 1)
    {
        throw ScopeEngineException(E_INCORRECT_IO_STREAM_COUNT_IN_BROADCAST, { inputCnt, outputCnt });
    }

    IOManager::CopyStream(IOManager::GetGlobal()->GetDevice(inputs[0].inputFileName), IOManager::GetGlobal()->GetDevice(outputs[0].outputFileName));
}
#endif //#if defined(COMPILE_NATIVE)


#endif //#if defined(COMPILE_INIT_SHUTDOWN)
#pragma region SV1_Extract_Split
#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_NATIVE)
    template<> 
    class SStreamV3ExtractPolicy<GetSStream_0_Data0, UID_GetSStream_0, NullSchema>
    {
    public:
        typedef NullSchema CorrelatedParameters;
        typedef bool (*PredFn)(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, CorrelatedParameters* params);

    public:
        typedef GetSStream_0_Data0 DataRowSchema;
        typedef Part_GetSStream_0 PartitionSchema;
        typedef Part_GetSStream_0 DataKeySchema;
        typedef RowComparePolicy<DataKeySchema, DataKeySchema, UID_GetSStream_0> DataKeyComparePolicy;
        typedef ResourceInputStream SystemResourceInputStream;

        static constexpr PartitioningType m_partitioning = RandomPartition;
        static constexpr bool m_residualFilterForKeyRange = false;
        static constexpr bool m_residualFilterForRefinedHash = false;
        static constexpr int  m_numberOfPartitionAfterRefinedHash = 0;
        static constexpr bool m_keyRangeSeek = false;
        static constexpr bool m_truncatedRangeKey = false;
        static constexpr bool m_readSelectedKeyRangesOnly = true;
        static constexpr bool m_generateMetadata = false;
        static constexpr UINT m_numOfBuffers = 4;
        static constexpr bool m_hasCorrelatedSchema = false;

        // FailFastSStreamRead ignores the maxUnavailability value and forces a fast failure in case of store errors
        static constexpr bool m_skipUnavailable = true; // MaxPercentInputUnavailability = 100

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>Column1</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Column2</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Column3</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static BYTE* DataColumnSizes()
        {
            static BYTE sizes[] = 
            {
                0,
                0,
                0,
            };

            return sizes;
        }
        static constexpr UINT m_dataColumnSizesCnt = 3;

        static BYTE* IndexColumnSizes()
        {
            static BYTE sizes[] = 
                {
                // Low key
                // Hi Key
                8, // BlockOffset
                8, // BlockLength
                4, // RowCount
                };

            return sizes;
        }
        static constexpr UINT m_indexColumnSizesCnt = 2 * 0 + 3;

        static UINT* SortKeys() { return nullptr; }
        static constexpr UINT m_sortKeysCnt = 0;

        static constexpr bool m_descending = false;


        static bool Deserialize(SSLibV3::ColumnIterator* iters, DataRowSchema & row, IncrementalAllocator* alloc, const BYTE* blockEnd, UINT32 defaultDistributionId, UINT64 defaultRowId)
        {
            STRUCTURED_DATA_ASSERT(iters[0].HasData(blockEnd));
            if (iters[0].IsNull())
            {
                row.m_Column1.SetNull();
            }
            else
            {
                row.m_Column1.CopyFromNotNull((FString::PointerType)iters[0].DataRaw(), (int)iters[0].Length(), alloc);
            }
            STRUCTURED_DATA_ASSERT(iters[1].HasData(blockEnd));
            if (iters[1].IsNull())
            {
                row.m_Column2.SetNull();
            }
            else
            {
                row.m_Column2.CopyFromNotNull((FString::PointerType)iters[1].DataRaw(), (int)iters[1].Length(), alloc);
            }
            STRUCTURED_DATA_ASSERT(iters[2].HasData(blockEnd));
            if (iters[2].IsNull())
            {
                row.m_Column3.SetNull();
            }
            else
            {
                row.m_Column3.CopyFromNotNull((FString::PointerType)iters[2].DataRaw(), (int)iters[2].Length(), alloc);
            }
            return true;
        }

        static void SkipRow(SSLibV3::ColumnIterator* iters)
        {
            if (iters[0].IsNull())
            {
                iters[0].IncrementNull();
            }
            else
            {
                iters[0].IncrementVariable();
            }
            if (iters[1].IsNull())
            {
                iters[1].IncrementNull();
            }
            else
            {
                iters[1].IncrementVariable();
            }
            if (iters[2].IsNull())
            {
                iters[2].IncrementNull();
            }
            else
            {
                iters[2].IncrementVariable();
            }
            //// Section of the Partition Key iterators skip.
            //// Section of the System column iterators skip.
        }

        //// The deserialize method that extract Partition Key values without advance any of the iterators.
        static UINT64 DeserializeDataKey(SSLibV3::ColumnIterator* iters, DataKeySchema& key, IncrementalAllocator* alloc, const BYTE* blockEnd, UINT64 defaultRowId)
        {
            return defaultRowId;
        }

        //// The deserialize method that extract current RowId without advance any of the iterators.
        static SStreamRowActionType DeserializeActionType(SSLibV3::ColumnIterator* iters, const BYTE* blockEnd)
        {
            return SStreamRowActionType::Insert;
        }

        static PredFn* PredicatesLow() { return nullptr; }
        static PredFn* PredicatesHi() { return nullptr; }
        static constexpr UINT m_predicateCnt = 0;
        // Predicate lookup generation warnings :
        //  -Condition expression is null.


        typedef void (*LookupKeySerializerFn)(const CorrelatedParameters& key, AutoBuffer& buffer, std::vector<SSLibV3::LookupColumnData>& keyData);
        typedef std::array<LookupKeySerializerFn, 0> LookupKeySerializerArray;
        static const LookupKeySerializerArray& LookupKeySerializers()
        {
            static LookupKeySerializerArray s_lookupKeySerializers = {
            };

            return s_lookupKeySerializers;
        }

        static bool LowIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        // PredicateRefinedHashResidual
        static bool PredicateRefinedHashResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, int partitionIndex, int numberOfPartitions)
        {
            return true;
 
        }
    };


#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<> 
    class RowComparePolicy<Part_GetSStream_0, Part_GetSStream_0, UID_GetSStream_0> 
    {
    public:
        // compare key from left and right schema object
        static int Compare(const Part_GetSStream_0 * left, const Part_GetSStream_0 * right)
        {
            return 0;
        }
    };
#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<>
    class SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>
    {
    public:
        SStreamV3OutputPolicy(UINT)
        {
        }

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>Column1</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Column2</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Column3</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static std::array<const char *, 3> m_columnNames;
        static std::array<const char *, 3> m_columnTypes;
        static std::array<BYTE, 3> m_dataColumnSizes;
        static std::array<BYTE, 3> m_indexColumnSizes;
        static UINT* m_dataPageSortKeys;
        static const char ** m_dataPageSortOrders;
        static const char *  m_dataPageSortUniq;
        static constexpr UINT m_dataPageSortKeysCnt = 0;

        static const char m_partitionType[];
        static constexpr UINT m_partitionColumnCount = 0;

        static UINT *     m_partitionKeys;
        static const char **  m_partitionOrders;
        static constexpr int m_blockSize = 4194304;
        static constexpr int m_uncompressedBlockSize = 190141770;
        static constexpr bool m_enableAutoPrimaryBloomFilter = true;
        static constexpr int m_bloomFilterSizeWriteRatio = -1;
        static constexpr int m_bloomFilterVersion = -1;
        static int GetPartitionIndex(const GetSStream_0_Data0& row)
        {
            // Global sstream outputter does not care partition index.
            UNREFERENCED_PARAMETER(row);
            return 0;
            
        }        
        static void SerializeRow(HANDLE rowHandle, AutoBuffer* buffer, int* columnOffsets, SIZE_T arraySize)
        {
            UNREFERENCED_PARAMETER(arraySize);
            
            GetSStream_0_Data0& row = *(GetSStream_0_Data0*)rowHandle;
            SStreamDataOutputStream output(buffer);

            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            if (row.m_Column1.IsNull())
            {
                ___masking___[0] |= 1;
            }
            if (row.m_Column2.IsNull())
            {
                ___masking___[0] |= 2;
            }
            if (row.m_Column3.IsNull())
            {
                ___masking___[0] |= 4;
            }
            auto rowStart = output.GetPosition();

            // write a null mask regardless whether there are nullable columns,
            // if there aren't any nullable column, simply write the array's 
            // initial values, which are zeros.
            output.Write(___masking___, sizeof(___masking___));


            columnOffsets[0] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Column1.IsNull())
            {
                output.Write(row.m_Column1);
            }

            columnOffsets[1] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Column2.IsNull())
            {
                output.Write(row.m_Column2);
            }

            columnOffsets[2] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Column3.IsNull())
            {
                output.Write(row.m_Column3);
            }

            columnOffsets[3] = (int)(output.GetPosition() - rowStart);
        }

        static constexpr SStreamVersion m_streamVersion = ScopeEngine::SStreamVersion::SSTREAM_VERSION_V3;
    };

#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<>
    class SStreamPartitionWriter<GetSStream_0_Data0, UID_SStreamOutput_1>
    {
    private:
        SStreamOutputStream<GetSStream_0_Data0, SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>, void, -1> sstreamOutputStream_0;
        BlockDevice*    m_metadataDevice;
        int             m_bufCount;
        int             m_sequenceNumber;
        int             m_distributionId;
        bool            m_preferSSD;
    public:
        static constexpr int VALUE_NOT_INITIALIZED = -3;

        
        SStreamPartitionWriter(OutputFileInfo outputs, const string& outputMetadataFileName, bool preferSSD, bool enableBloomFilter)
            : SStreamPartitionWriter(&outputs, 1, outputMetadataFileName, preferSSD, enableBloomFilter)
        {
        }

        
        SStreamPartitionWriter(OutputFileInfo* outputs, int fileCnt, const string& outputMetadataFileName, bool preferSSD, bool enableBloomFilter)
            : m_bufCount(0)
            , m_sequenceNumber(VALUE_NOT_INITIALIZED)
            , m_preferSSD(preferSSD)
            , m_distributionId(0)
            
            , sstreamOutputStream_0(outputs[0].outputFileName, 0, outputs[0].bufferSize, outputs[0].bufferCount, preferSSD, enableBloomFilter)
            , m_metadataDevice(ScopeEngine::IOManager::GetGlobal()->GetDevice(outputMetadataFileName))
        {
            STRUCTURED_DATA_ASSERT(fileCnt == 1);

            for(int idx = 0; idx < fileCnt; ++idx)
            {
                m_bufCount = std::max(m_bufCount, outputs[idx].bufferCount);
            }
        }

        void Init()
        {
            constexpr int64_t expectedNumberOfRowsPerPartition_0 = 10737418ll;
            sstreamOutputStream_0.Init(expectedNumberOfRowsPerPartition_0);
        }

        void SetSequenceNumber(int sequenceNumber)
        {
            m_sequenceNumber = sequenceNumber;
            m_distributionId = 0;
        }

        bool NeedMetadata()
        {
            return -1 != -1;
        }

        void SetPartitionInfo(PartitionMetadata* payload)
        {
            sstreamOutputStream_0.SetPartitionInfo(payload);
            // If the m_distributionId hasn't been set, then we can initialize it
            // If the first OutputStream has a valid PartitionID, then use it. 
            // do we have a value from our payload?
            // all column groups must have the same distribution id, so just use the first group
            if(sstreamOutputStream_0.ValidPartition())
            {
                m_distributionId = sstreamOutputStream_0.GetPartitionIndex();
            }
        }

        bool ValidPartition()
        {
            return m_distributionId != PartitionMetadata::PARTITION_NOT_EXIST;
        }

        void AppendRow(GetSStream_0_Data0 & output)
        {
            sstreamOutputStream_0.AppendRow(output);
        }

        void Close()
        {
            sstreamOutputStream_0.Close();


            unique_ptr<SStreamMetadata> metadata(SStreamMetadata::CreateMetadataByVersion(ScopeEngine::SStreamVersion::SSTREAM_VERSION_V3, MemoryManager::GetGlobal()));
            std::string streamSchema = std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>Column1</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Column2</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Column3</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" };

            shared_ptr<vector<ScopeEngine::SSLibV3::ColumnGroupInfo>> colGroupInfos = make_shared<vector<ScopeEngine::SSLibV3::ColumnGroupInfo>>(1);
            shared_ptr<vector<ScopeEngine::SSLibV3::DataunitTableRow>> dataUnitTableRows = make_shared<vector<ScopeEngine::SSLibV3::DataunitTableRow>>(1);
            shared_ptr<ScopeEngine::SSLibV3::SStreamStatistics> statistics;
            statistics = sstreamOutputStream_0.GetStatistics();
            std::string dataSchema_0 = SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::DataSchemaString();

            ScopeEngine::SSLibV3::ColumnGroupInfo& colGroupInfo_0 = (*colGroupInfos)[0];
            colGroupInfo_0.m_columnGroupIndex = 0;
            colGroupInfo_0.m_columnGroupSchema = dataSchema_0;

            ScopeEngine::SSLibV3::DataunitTableRow& dataunitInfo_0 = (*dataUnitTableRows)[0];
            dataunitInfo_0.m_PartitionIndex = m_distributionId;
            dataunitInfo_0.m_ColumnGroupIndex = 0;
            dataunitInfo_0.m_Offset = 0;
            dataunitInfo_0.m_Length = sstreamOutputStream_0.Length();
            dataunitInfo_0.m_DataLength = sstreamOutputStream_0.DataLength();
            dataunitInfo_0.m_RowCount = sstreamOutputStream_0.RowCount();
            dataunitInfo_0.m_DeltaIndex = 0;

            shared_ptr<vector<ScopeEngine::SSLibV3::PartitionInfoTableRow>> partInfoRows = make_shared<vector<ScopeEngine::SSLibV3::PartitionInfoTableRow>>(1);
            ScopeEngine::SSLibV3::PartitionInfoTableRow& partInfo = (*partInfoRows)[0];
            // all column groups have the same partition information
            partInfo.m_PartitionKeyRange = sstreamOutputStream_0.GetPartitionKeyRange();
            partInfo.m_BeginPartitionIndex = m_distributionId;
            partInfo.m_AffinityId = GuidToString(sstreamOutputStream_0.GetAffinityGuid());

            metadata->Initialize(streamSchema,
                colGroupInfos,
                dataUnitTableRows,
                partInfoRows,
                statistics);

            metadata->PreferSSD(m_preferSSD);
            metadata->Write(m_metadataDevice);
        }

        LONGLONG GetTotalIoWaitTime() const
        {
            LONGLONG time = 0;
            time += sstreamOutputStream_0.GetTotalIoWaitTime();
            return time;
        }

        void WriteRuntimeStats(TreeNode & root) const
        {
            sstreamOutputStream_0.WriteRuntimeStats(root);
        }

        // get operator resource requirements
        ScopeEngine::OperatorRequirements GetOperatorRequirements(SIZE_T bufferCount)
        {
            return ScopeEngine::OperatorRequirements()
                .AddMemoryForOutputSStreams(1, Configuration::GetGlobal().GetMaxInMemoryRowSize(), m_bufCount);
        }

        // the following methods are for SplitOutputter
        void WriteMetadata(PartitionMetadata* metadata)
        {
            SetPartitionInfo(metadata);
        }

        void Finish()
        {
            // do nothing
        }

        void Flush(bool forcePersistent = false)
        {
            // do nothing
            (forcePersistent);
        }
    };

#endif


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    using SStreamV3ExtractorType_SV1_Extr_Split_GetSStream_0 = SStreamExtractorV4<GetSStream_0_Data0, SStreamV3ExtractPolicy<GetSStream_0_Data0, UID_GetSStream_0, NullSchema>, UID_GetSStream_0, NullSchema, false>;
    SStreamV3ExtractorType_SV1_Extr_Split_GetSStream_0 * CreateExtractor_SV1_Extr_Split_GetSStream_0(unique_ptr<SStreamV3ExtractorType_SV1_Extr_Split_GetSStream_0> * extractor_ptr)
    {
        extractor_ptr->reset(new SStreamV3ExtractorType_SV1_Extr_Split_GetSStream_0(0, "", UID_GetSStream_0));
        return extractor_ptr->get();
    }
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
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        unique_ptr<SStreamV3ExtractorType_SV1_Extr_Split_GetSStream_0> extractor_0_ptr;
        SStreamV3ExtractorType_SV1_Extr_Split_GetSStream_0 * extractor_0 = CreateExtractor_SV1_Extr_Split_GetSStream_0(&extractor_0_ptr);
        ULONG extractor_0_count = 1;


        using OutputterType1_SV1_Extr_Split = SStreamOutputter<SStreamV3ExtractorType_SV1_Extr_Split_GetSStream_0, GetSStream_0_Data0, UID_SStreamOutput_1>;

        // Construct operator and initialize it
        unique_ptr<OutputterType1_SV1_Extr_Split> outputter_SStreamOutput_1_ptr(new OutputterType1_SV1_Extr_Split(extractor_0, &outputs[0], 1, outputs[1].outputFileName, false, UID_SStreamOutput_1, false));
        OutputterType1_SV1_Extr_Split * outputter_SStreamOutput_1 = outputter_SStreamOutput_1_ptr.get();

        if (argv != nullptr && argc > 0)
        {
            try
            {
                int sequenceNumber = GetSequenceNumber(argv, argc);
                outputter_SStreamOutput_1->SetSequenceNumber(sequenceNumber);
            }
            catch(const RuntimeException&)
            {
                // Sequence number will remain 0 in outputter_SStreamOutput_1.
            }
        }
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SStreamOutput_1) };

        try
        {
            // Init operator chain
            outputter_SStreamOutput_1->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            GetSStream_0_Data0 row;
            outputter_SStreamOutput_1->GetNextRow(row);

            // Close operator chain
            outputter_SStreamOutput_1->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SStreamOutput_1->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV1_Extract_Split
#pragma region SV2_Aggregate
#if defined(COMPILE_SV2_AGGREGATE) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<Part_GetSStream_0,UID_SStreamMetadataOutput_3>
    {
    public:
        struct KeyStruct
        {

            KeyStruct(Part_GetSStream_0 & c) 

            {
            }

            KeyStruct(const Part_GetSStream_0 & c, IncrementalAllocator * alloc) 

            {
            }

            KeyStruct(KeyStruct & c) 

            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) 

            {
            }

            KeyStruct() 

            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {
                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Part_GetSStream_0 & row, KeyType & key)
        {
            int r = 0;
            return r;
        }

        static int Compare(Part_GetSStream_0 * n1, Part_GetSStream_0 * n2)
        {
            int r = 0;
            return r;
        }

    };



#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV2_Agg : SStreamMetadataExtractor<GetSStream_0_Data0> { using SStreamMetadataExtractor<GetSStream_0_Data0>::SStreamMetadataExtractor; };
struct MetadataAggregateType_MetadataAggregate_2 : Merger<ExtractorType1_SV2_Agg, GetSStream_0_Data0, ScopeUnionAll<ExtractorType1_SV2_Agg, GetSStream_0_Data0>, UID_MetadataAggregate_2> { using Merger<ExtractorType1_SV2_Agg, GetSStream_0_Data0, ScopeUnionAll<ExtractorType1_SV2_Agg, GetSStream_0_Data0>, UID_MetadataAggregate_2>::Merger; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV2_Aggregate_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // remove the empty stream
        // For the case "PARTITION_NOT_EXIST", the output stream is blank. So here the input stream may be blank.
        int inputIdx2 = 0;
        
        for (int inputIdx = 0; inputIdx < inputCnt; ++inputIdx)
        {
            if(inputs[inputIdx].length == 0)
            {
                continue;
            }
            inputs[inputIdx2] = inputs[inputIdx];
            ++inputIdx2;
        }
        inputCnt =inputIdx2;

        // ExtractorType1_SV2_Agg: SStreamMetadataExtractor<GetSStream_0_Data0>
        unique_ptr<unique_ptr<ExtractorType1_SV2_Agg>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV2_Agg>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV2_Agg(inputs[i], i, false, false, UID_SV1_Extract_Split_out1));
        }

    ExtractorType1_SV2_Agg ** extractor_0 = (ExtractorType1_SV2_Agg **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // MetadataAggregateType_MetadataAggregate_2: Merger<ExtractorType1_SV2_Agg, GetSStream_0_Data0, ScopeUnionAll<ExtractorType1_SV2_Agg, GetSStream_0_Data0>, UID_MetadataAggregate_2>
        unique_ptr<MetadataAggregateType_MetadataAggregate_2> metadataAggregate_MetadataAggregate_2_ptr(new MetadataAggregateType_MetadataAggregate_2(extractor_0, extractor_0_count, false, UID_MetadataAggregate_2));
        MetadataAggregateType_MetadataAggregate_2* metadataAggregate_MetadataAggregate_2 = metadataAggregate_MetadataAggregate_2_ptr.get();

        using OutputterType2_SV2_Agg = SStreamMetadataOutputter<MetadataAggregateType_MetadataAggregate_2, GetSStream_0_Data0, Part_GetSStream_0, UID_SStreamMetadataOutput_3>;
        unique_ptr<OutputterType2_SV2_Agg> outputter_SStreamMetadataOutput_3_ptr(new OutputterType2_SV2_Agg(metadataAggregate_MetadataAggregate_2, outputs[0].outputFileName, "", false, false, 0, UID_SStreamMetadataOutput_3));
        OutputterType2_SV2_Agg * outputter_SStreamMetadataOutput_3 = outputter_SStreamMetadataOutput_3_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SStreamMetadataOutput_3) };

        try
        {
            // Init operator chain
            outputter_SStreamMetadataOutput_3->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            GetSStream_0_Data0 row;
            outputter_SStreamMetadataOutput_3->GetNextRow(row);

            // Close operator chain
            outputter_SStreamMetadataOutput_3->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SStreamMetadataOutput_3->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV2_Aggregate
#pragma region SV3_Extract
#if defined(COMPILE_SV3_EXTRACT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_NATIVE)
    template<> 
    class TextExtractPolicy<SV3_Extract_out0, UID_Extract_4>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, SV3_Extract_out0 & row)
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

                    input->Read(row.m_BingAdsUserId);
                    input->Read(row.m_MsAlias);
                    input->Read(row.m_UcmUserId);

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
                            { input->CurrentLineNumber() - 1, 3, input->CurrentField() },
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
            static const std::array<const char*, 4> c_columnNames =
            {
                "BingAdsUserId",
                "MsAlias",
                "UcmUserId",
                "*** END ***"
            };

            auto idx = std::min(columnIndex, c_columnNames.size() - 1);
            return c_columnNames[idx];
        }
    };

#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV3_Extr : Extractor<SV3_Extract_out0, TextExtractPolicy<SV3_Extract_out0, UID_Extract_4>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<SV3_Extract_out0, TextExtractPolicy<SV3_Extract_out0, UID_Extract_4>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct UnionAllType_Extract_4_SV3_Extract_out0_connector : ParallelUnionAll<ExtractorType1_SV3_Extr, SV3_Extract_out0, true> { using ParallelUnionAll<ExtractorType1_SV3_Extr, SV3_Extract_out0, true>::ParallelUnionAll; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV3_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV3_Extr: Extractor<SV3_Extract_out0, TextExtractPolicy<SV3_Extract_out0, UID_Extract_4>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV3_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV3_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV3_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_4));
        }

    ExtractorType1_SV3_Extr ** extractor_0 = (ExtractorType1_SV3_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_Extract_4_SV3_Extract_out0_connector: ParallelUnionAll<ExtractorType1_SV3_Extr, SV3_Extract_out0, true>
        unique_ptr<UnionAllType_Extract_4_SV3_Extract_out0_connector> unionall_Extract_4_SV3_Extract_out0_connector_ptr(new UnionAllType_Extract_4_SV3_Extract_out0_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_4));
        UnionAllType_Extract_4_SV3_Extract_out0_connector * unionall_Extract_4_SV3_Extract_out0_connector = unionall_Extract_4_SV3_Extract_out0_connector_ptr.get();
        ULONG unionall_Extract_4_SV3_Extract_out0_connector_count = 1;

        using OutputterType2_SV3_Extr = Outputter<UnionAllType_Extract_4_SV3_Extract_out0_connector, SV3_Extract_out0, BinaryOutputPolicy<SV3_Extract_out0>, BinaryOutputStream, false>;
        unique_ptr<OutputterType2_SV3_Extr> outputter_SV3_Extract_out0_ptr(new OutputterType2_SV3_Extr(unionall_Extract_4_SV3_Extract_out0_connector, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, UID_SV3_Extract_out0, false));
        OutputterType2_SV3_Extr * outputter_SV3_Extract_out0 = outputter_SV3_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV3_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV3_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            SV3_Extract_out0 row;
            outputter_SV3_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV3_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV3_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV3_Extract
#pragma region SV4_Extract_Split
#if defined(COMPILE_SV4_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_NATIVE)
    template<>
    class SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>
    {
    public:
        SStreamV3OutputPolicy(UINT)
        {
        }

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>UserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Start</Name>\r\n      <Type>DateTime</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Region</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Query</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Duration</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Urls</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>ClickedUrls</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static std::array<const char *, 7> m_columnNames;
        static std::array<const char *, 7> m_columnTypes;
        static std::array<BYTE, 7> m_dataColumnSizes;
        static std::array<BYTE, 3> m_indexColumnSizes;
        static UINT* m_dataPageSortKeys;
        static const char ** m_dataPageSortOrders;
        static const char *  m_dataPageSortUniq;
        static constexpr UINT m_dataPageSortKeysCnt = 0;

        static const char m_partitionType[];
        static constexpr UINT m_partitionColumnCount = 0;

        static UINT *     m_partitionKeys;
        static const char **  m_partitionOrders;
        static constexpr int m_blockSize = 4194304;
        static constexpr int m_uncompressedBlockSize = 12455800;
        static constexpr bool m_enableAutoPrimaryBloomFilter = true;
        static constexpr int m_bloomFilterSizeWriteRatio = -1;
        static constexpr int m_bloomFilterVersion = -1;
        static int GetPartitionIndex(const Extract_16_Data0& row)
        {
            // Global sstream outputter does not care partition index.
            UNREFERENCED_PARAMETER(row);
            return 0;
            
        }        
        static void SerializeRow(HANDLE rowHandle, AutoBuffer* buffer, int* columnOffsets, SIZE_T arraySize)
        {
            UNREFERENCED_PARAMETER(arraySize);
            
            Extract_16_Data0& row = *(Extract_16_Data0*)rowHandle;
            SStreamDataOutputStream output(buffer);

            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            if (row.m_Region.IsNull())
            {
                ___masking___[0] |= 4;
            }
            if (row.m_Query.IsNull())
            {
                ___masking___[0] |= 8;
            }
            if (row.m_Urls.IsNull())
            {
                ___masking___[0] |= 32;
            }
            if (row.m_ClickedUrls.IsNull())
            {
                ___masking___[0] |= 64;
            }
            auto rowStart = output.GetPosition();

            // write a null mask regardless whether there are nullable columns,
            // if there aren't any nullable column, simply write the array's 
            // initial values, which are zeros.
            output.Write(___masking___, sizeof(___masking___));


            columnOffsets[0] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_UserId);

            columnOffsets[1] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_Start);

            columnOffsets[2] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Region.IsNull())
            {
                output.Write(row.m_Region);
            }

            columnOffsets[3] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Query.IsNull())
            {
                output.Write(row.m_Query);
            }

            columnOffsets[4] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_Duration);

            columnOffsets[5] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Urls.IsNull())
            {
                output.Write(row.m_Urls);
            }

            columnOffsets[6] = (int)(output.GetPosition() - rowStart);
            if (!row.m_ClickedUrls.IsNull())
            {
                output.Write(row.m_ClickedUrls);
            }

            columnOffsets[7] = (int)(output.GetPosition() - rowStart);
        }

        static constexpr SStreamVersion m_streamVersion = ScopeEngine::SStreamVersion::SSTREAM_VERSION_V3;
    };

#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<>
    class SStreamPartitionWriter<Extract_16_Data0, UID_SV4_Extract_Split_out0>
    {
    private:
        SStreamOutputStream<Extract_16_Data0, SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>, void, -1> sstreamOutputStream_0;
        BlockDevice*    m_metadataDevice;
        int             m_bufCount;
        int             m_sequenceNumber;
        int             m_distributionId;
        bool            m_preferSSD;
    public:
        static constexpr int VALUE_NOT_INITIALIZED = -3;

        
        SStreamPartitionWriter(OutputFileInfo outputs, const string& outputMetadataFileName, bool preferSSD, bool enableBloomFilter)
            : SStreamPartitionWriter(&outputs, 1, outputMetadataFileName, preferSSD, enableBloomFilter)
        {
        }

        
        SStreamPartitionWriter(OutputFileInfo* outputs, int fileCnt, const string& outputMetadataFileName, bool preferSSD, bool enableBloomFilter)
            : m_bufCount(0)
            , m_sequenceNumber(VALUE_NOT_INITIALIZED)
            , m_preferSSD(preferSSD)
            , m_distributionId(0)
            
            , sstreamOutputStream_0(outputs[0].outputFileName, 0, outputs[0].bufferSize, outputs[0].bufferCount, preferSSD, enableBloomFilter)
            , m_metadataDevice(ScopeEngine::IOManager::GetGlobal()->GetDevice(outputMetadataFileName))
        {
            STRUCTURED_DATA_ASSERT(fileCnt == 1);

            for(int idx = 0; idx < fileCnt; ++idx)
            {
                m_bufCount = std::max(m_bufCount, outputs[idx].bufferCount);
            }
        }

        void Init()
        {
            constexpr int64_t expectedNumberOfRowsPerPartition_0 = 4995000000ll;
            sstreamOutputStream_0.Init(expectedNumberOfRowsPerPartition_0);
        }

        void SetSequenceNumber(int sequenceNumber)
        {
            m_sequenceNumber = sequenceNumber;
            m_distributionId = 0;
        }

        bool NeedMetadata()
        {
            return -1 != -1;
        }

        void SetPartitionInfo(PartitionMetadata* payload)
        {
            sstreamOutputStream_0.SetPartitionInfo(payload);
            // If the m_distributionId hasn't been set, then we can initialize it
            // If the first OutputStream has a valid PartitionID, then use it. 
            // do we have a value from our payload?
            // all column groups must have the same distribution id, so just use the first group
            if(sstreamOutputStream_0.ValidPartition())
            {
                m_distributionId = sstreamOutputStream_0.GetPartitionIndex();
            }
        }

        bool ValidPartition()
        {
            return m_distributionId != PartitionMetadata::PARTITION_NOT_EXIST;
        }

        void AppendRow(Extract_16_Data0 & output)
        {
            sstreamOutputStream_0.AppendRow(output);
        }

        void Close()
        {
            sstreamOutputStream_0.Close();


            unique_ptr<SStreamMetadata> metadata(SStreamMetadata::CreateMetadataByVersion(ScopeEngine::SStreamVersion::SSTREAM_VERSION_V3, MemoryManager::GetGlobal()));
            std::string streamSchema = std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>UserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Start</Name>\r\n      <Type>DateTime</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Region</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Query</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Duration</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Urls</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>ClickedUrls</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" };

            shared_ptr<vector<ScopeEngine::SSLibV3::ColumnGroupInfo>> colGroupInfos = make_shared<vector<ScopeEngine::SSLibV3::ColumnGroupInfo>>(1);
            shared_ptr<vector<ScopeEngine::SSLibV3::DataunitTableRow>> dataUnitTableRows = make_shared<vector<ScopeEngine::SSLibV3::DataunitTableRow>>(1);
            shared_ptr<ScopeEngine::SSLibV3::SStreamStatistics> statistics;
            statistics = sstreamOutputStream_0.GetStatistics();
            std::string dataSchema_0 = SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::DataSchemaString();

            ScopeEngine::SSLibV3::ColumnGroupInfo& colGroupInfo_0 = (*colGroupInfos)[0];
            colGroupInfo_0.m_columnGroupIndex = 0;
            colGroupInfo_0.m_columnGroupSchema = dataSchema_0;

            ScopeEngine::SSLibV3::DataunitTableRow& dataunitInfo_0 = (*dataUnitTableRows)[0];
            dataunitInfo_0.m_PartitionIndex = m_distributionId;
            dataunitInfo_0.m_ColumnGroupIndex = 0;
            dataunitInfo_0.m_Offset = 0;
            dataunitInfo_0.m_Length = sstreamOutputStream_0.Length();
            dataunitInfo_0.m_DataLength = sstreamOutputStream_0.DataLength();
            dataunitInfo_0.m_RowCount = sstreamOutputStream_0.RowCount();
            dataunitInfo_0.m_DeltaIndex = 0;

            shared_ptr<vector<ScopeEngine::SSLibV3::PartitionInfoTableRow>> partInfoRows = make_shared<vector<ScopeEngine::SSLibV3::PartitionInfoTableRow>>(1);
            ScopeEngine::SSLibV3::PartitionInfoTableRow& partInfo = (*partInfoRows)[0];
            // all column groups have the same partition information
            partInfo.m_PartitionKeyRange = sstreamOutputStream_0.GetPartitionKeyRange();
            partInfo.m_BeginPartitionIndex = m_distributionId;
            partInfo.m_AffinityId = GuidToString(sstreamOutputStream_0.GetAffinityGuid());

            metadata->Initialize(streamSchema,
                colGroupInfos,
                dataUnitTableRows,
                partInfoRows,
                statistics);

            metadata->PreferSSD(m_preferSSD);
            metadata->Write(m_metadataDevice);
        }

        LONGLONG GetTotalIoWaitTime() const
        {
            LONGLONG time = 0;
            time += sstreamOutputStream_0.GetTotalIoWaitTime();
            return time;
        }

        void WriteRuntimeStats(TreeNode & root) const
        {
            sstreamOutputStream_0.WriteRuntimeStats(root);
        }

        // get operator resource requirements
        ScopeEngine::OperatorRequirements GetOperatorRequirements(SIZE_T bufferCount)
        {
            return ScopeEngine::OperatorRequirements()
                .AddMemoryForOutputSStreams(1, Configuration::GetGlobal().GetMaxInMemoryRowSize(), m_bufCount);
        }

        // the following methods are for SplitOutputter
        void WriteMetadata(PartitionMetadata* metadata)
        {
            SetPartitionInfo(metadata);
        }

        void Finish()
        {
            // do nothing
        }

        void Flush(bool forcePersistent = false)
        {
            // do nothing
            (forcePersistent);
        }
    };

#endif


#if defined(COMPILE_NATIVE)
    template<> 
    class TextExtractPolicy<Extract_16_Data0, UID_Extract_16>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_16_Data0 & row)
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

                    input->Read(row.m_UserId);
                    input->Read(row.m_Start);
                    input->Read(row.m_Region);
                    input->Read(row.m_Query);
                    input->Read(row.m_Duration);
                    input->Read(row.m_Urls);
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
                            { input->CurrentLineNumber() - 1, 7, input->CurrentField() },
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
            static const std::array<const char*, 8> c_columnNames =
            {
                "UserId",
                "Start",
                "Region",
                "Query",
                "Duration",
                "Urls",
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
    class TextOutputPolicy<Extract_16_Data0, UID_Output_35>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_16_Data0 & row)
        {
            output->Write<int,false>(row.m_UserId);
            output->WriteDelimiter();
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Region.IsNull())
            {
                output->Write<FString,false>(row.m_Region);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Duration);
            output->WriteDelimiter();
            if (!row.m_Urls.IsNull())
            {
                output->Write<FString,false>(row.m_Urls);
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
    class TextOutputPolicy<Extract_16_Data0, UID_Output_36>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_16_Data0 & row)
        {
            output->Write<int,false>(row.m_UserId);
            output->WriteDelimiter();
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Region.IsNull())
            {
                output->Write<FString,false>(row.m_Region);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Duration);
            output->WriteDelimiter();
            if (!row.m_Urls.IsNull())
            {
                output->Write<FString,false>(row.m_Urls);
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
    class TextOutputPolicy<Extract_16_Data0, UID_Output_37>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_16_Data0 & row)
        {
            output->Write<int,false>(row.m_UserId);
            output->WriteDelimiter();
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Region.IsNull())
            {
                output->Write<FString,false>(row.m_Region);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Duration);
            output->WriteDelimiter();
            if (!row.m_Urls.IsNull())
            {
                output->Write<FString,false>(row.m_Urls);
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



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

    static const char * StringTable_Split_17_1 [] =
    {
        "UserId",
        "Start",
        "Region",
        "Query",
        "Duration",
        "Urls",
        "ClickedUrls",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_16_Data0, Extract_16_Data0, UID_Split_17_1>
    {
    public:
        void Init(ManagedRow<Extract_16_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_16_Data0 & input, Extract_16_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_UserId = input.m_UserId;
                exceptionIndex++;
                output.m_Start = input.m_Start;
                exceptionIndex++;
                output.m_Region = input.m_Region;
                exceptionIndex++;
                output.m_Query = input.m_Query;
                exceptionIndex++;
                output.m_Duration = input.m_Duration;
                exceptionIndex++;
                output.m_Urls = input.m_Urls;
                exceptionIndex++;
                output.m_ClickedUrls = input.m_ClickedUrls;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_17_1[exceptionIndex]));
            }
        }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Split_17_2 [] =
    {
        "UserId",
        "Start",
        "Region",
        "Query",
        "Duration",
        "Urls",
        "ClickedUrls",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_16_Data0, Extract_16_Data0, UID_Split_17_2>
    {
    public:
        void Init(ManagedRow<Extract_16_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_16_Data0 & input, Extract_16_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_UserId = input.m_UserId;
                exceptionIndex++;
                output.m_Start = input.m_Start;
                exceptionIndex++;
                output.m_Region = input.m_Region;
                exceptionIndex++;
                output.m_Query = input.m_Query;
                exceptionIndex++;
                output.m_Duration = input.m_Duration;
                exceptionIndex++;
                output.m_Urls = input.m_Urls;
                exceptionIndex++;
                output.m_ClickedUrls = input.m_ClickedUrls;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_17_2[exceptionIndex]));
            }
        }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Split_17_3 [] =
    {
        "UserId",
        "Start",
        "Region",
        "Query",
        "Duration",
        "Urls",
        "ClickedUrls",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_16_Data0, Extract_16_Data0, UID_Split_17_3>
    {
    public:
        void Init(ManagedRow<Extract_16_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_16_Data0 & input, Extract_16_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_UserId = input.m_UserId;
                exceptionIndex++;
                output.m_Start = input.m_Start;
                exceptionIndex++;
                output.m_Region = input.m_Region;
                exceptionIndex++;
                output.m_Query = input.m_Query;
                exceptionIndex++;
                output.m_Duration = input.m_Duration;
                exceptionIndex++;
                output.m_Urls = input.m_Urls;
                exceptionIndex++;
                output.m_ClickedUrls = input.m_ClickedUrls;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_17_3[exceptionIndex]));
            }
        }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Split_17_4 [] =
    {
        "UserId",
        "Start",
        "Region",
        "Query",
        "Duration",
        "Urls",
        "ClickedUrls",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_16_Data0, Extract_16_Data0, UID_Split_17_4>
    {
    public:
        void Init(ManagedRow<Extract_16_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_16_Data0 & input, Extract_16_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_UserId = input.m_UserId;
                exceptionIndex++;
                output.m_Start = input.m_Start;
                exceptionIndex++;
                output.m_Region = input.m_Region;
                exceptionIndex++;
                output.m_Query = input.m_Query;
                exceptionIndex++;
                output.m_Duration = input.m_Duration;
                exceptionIndex++;
                output.m_Urls = input.m_Urls;
                exceptionIndex++;
                output.m_ClickedUrls = input.m_ClickedUrls;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_17_4[exceptionIndex]));
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
    class SplitPolicy<typename Extract_16_Data0, UID_Split_17>
    {
        int bufferCount[5];
        std::size_t bufferSize[5];
        
        typedef SplitOutputterSentinel<Extract_16_Data0> SplitOutputType_Split_17_5;
        SplitOutputType_Split_17_5 splitOutputter_Split_17_5;

        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<Extract_16_Data0, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, TextOutputPolicy<Extract_16_Data0, UID_Output_37>> OutputPolicyWrapperType_Split_17_4;

        typedef SplitOutputter<
            SplitOutputType_Split_17_5, 
            Extract_16_Data0, 
            OutputPolicyWrapperType_Split_17_4, 
            ExecutionStats, 
            UID_Split_17_4> 
            SplitOutputType_Split_17_4;

        SplitOutputType_Split_17_4 splitOutputter_Split_17_4;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<Extract_16_Data0, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, TextOutputPolicy<Extract_16_Data0, UID_Output_36>> OutputPolicyWrapperType_Split_17_3;

        typedef SplitOutputter<
            SplitOutputType_Split_17_4, 
            Extract_16_Data0, 
            OutputPolicyWrapperType_Split_17_3, 
            ExecutionStats, 
            UID_Split_17_3> 
            SplitOutputType_Split_17_3;

        SplitOutputType_Split_17_3 splitOutputter_Split_17_3;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<Extract_16_Data0, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, TextOutputPolicy<Extract_16_Data0, UID_Output_35>> OutputPolicyWrapperType_Split_17_2;

        typedef SplitOutputter<
            SplitOutputType_Split_17_3, 
            Extract_16_Data0, 
            OutputPolicyWrapperType_Split_17_2, 
            ExecutionStats, 
            UID_Split_17_2> 
            SplitOutputType_Split_17_2;

        SplitOutputType_Split_17_2 splitOutputter_Split_17_2;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<Extract_16_Data0, SStreamPartitionWriter<Extract_16_Data0, UID_SV4_Extract_Split_out0>, SplitterSStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>> OutputPolicyWrapperType_Split_17_0;

        typedef SplitOutputter<
            SplitOutputType_Split_17_2, 
            Extract_16_Data0, 
            OutputPolicyWrapperType_Split_17_0, 
            ExecutionStats, 
            UID_Split_17_1> 
            SplitOutputType_Split_17_0;

        SplitOutputType_Split_17_0 splitOutputter_Split_17_0;


    public:
        SplitPolicy(OutputFileInfo * outputFiles) :
            splitOutputter_Split_17_4(&splitOutputter_Split_17_5, new OutputPolicyWrapperType_Split_17_4(outputFiles[4].outputFileName, outputFiles[4].bufferSize, outputFiles[4].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), false), outputFiles[4].outputFileName, false, UID_SV4_Extract_Split_out4),
            splitOutputter_Split_17_3(&splitOutputter_Split_17_4, new OutputPolicyWrapperType_Split_17_3(outputFiles[3].outputFileName, outputFiles[3].bufferSize, outputFiles[3].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), false), outputFiles[3].outputFileName, false, UID_SV4_Extract_Split_out3),
            splitOutputter_Split_17_2(&splitOutputter_Split_17_3, new OutputPolicyWrapperType_Split_17_2(outputFiles[2].outputFileName, outputFiles[2].bufferSize, outputFiles[2].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), false), outputFiles[2].outputFileName, false, UID_SV4_Extract_Split_out2),
            splitOutputter_Split_17_0(&splitOutputter_Split_17_2, new OutputPolicyWrapperType_Split_17_0(outputFiles[0].outputFileName, outputFiles[0].bufferSize, outputFiles[0].bufferCount, OutputSStreamParameters(1, false, outputFiles[1].outputFileName), false), outputFiles[0].outputFileName, false, UID_SV4_Extract_Split_out0)
        {
            for(int idx = 0; idx < 5; ++idx)
            {
                bufferCount[idx] = outputFiles[idx].bufferCount;
                bufferSize[idx] = outputFiles[idx].bufferSize;
            }
        }

        void SetSequenceNumber(int sequenceNumber)
        {
            splitOutputter_Split_17_4.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_17_3.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_17_2.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_17_0.SetSequenceNumber(sequenceNumber);
        }

        void Init()
        {
            
            splitOutputter_Split_17_0.Init(nullptr);
        }

        void BeginDataRead()
        {
            splitOutputter_Split_17_0.BeginDataRead();
        }

        void Close()
        {
            splitOutputter_Split_17_0.Close();
        }

        void ProcessMetadata(PartitionMetadata * metadata)
        {
            splitOutputter_Split_17_0.ProcessMetadata(metadata);
        }

        void OutputHeader()
        {
            splitOutputter_Split_17_0.OutputHeader();
        }

        void ProcessRow(Extract_16_Data0 & input)
        {
            splitOutputter_Split_17_0.ProcessRow(input);
        }

        __declspec(noinline)
        void WriteRuntimeStats(TreeNode & root) const
        {
            splitOutputter_Split_17_0.WriteRuntimeStats(root);
        }

        LONGLONG GetTotalIoWaitTime() const
        {
            return splitOutputter_Split_17_0.GetTotalIoWaitTime();
        }

        // get operator resource requirements
        ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return splitOutputter_Split_17_0.GetOperatorRequirements()
	.AddMemoryForOutputUStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), bufferCount[4])
	.AddMemoryForOutputUStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), bufferCount[3])
	.AddMemoryForOutputUStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), bufferCount[2])
	.AddMemoryForOutputSStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), bufferCount[0]);
        }

        void FlushOutput(bool forcePersistent = false)
        {
            splitOutputter_Split_17_0.FlushOutput(forcePersistent);
        }

    };

#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV4_Extr_Split : Extractor<Extract_16_Data0, TextExtractPolicy<Extract_16_Data0, UID_Extract_16>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<Extract_16_Data0, TextExtractPolicy<Extract_16_Data0, UID_Extract_16>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct UnionAllType_Extract_16_Split_17_connector : ParallelUnionAll<ExtractorType1_SV4_Extr_Split, Extract_16_Data0, true> { using ParallelUnionAll<ExtractorType1_SV4_Extr_Split, Extract_16_Data0, true>::ParallelUnionAll; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV4_Extract_Split_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV4_Extr_Split: Extractor<Extract_16_Data0, TextExtractPolicy<Extract_16_Data0, UID_Extract_16>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV4_Extr_Split>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV4_Extr_Split>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV4_Extr_Split(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_16));
        }

    ExtractorType1_SV4_Extr_Split ** extractor_0 = (ExtractorType1_SV4_Extr_Split **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_Extract_16_Split_17_connector: ParallelUnionAll<ExtractorType1_SV4_Extr_Split, Extract_16_Data0, true>
        unique_ptr<UnionAllType_Extract_16_Split_17_connector> unionall_Extract_16_Split_17_connector_ptr(new UnionAllType_Extract_16_Split_17_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_16));
        UnionAllType_Extract_16_Split_17_connector * unionall_Extract_16_Split_17_connector = unionall_Extract_16_Split_17_connector_ptr.get();
        ULONG unionall_Extract_16_Split_17_connector_count = 1;

        using SplitterType_Split_17 = Splitter<UnionAllType_Extract_16_Split_17_connector, Extract_16_Data0, false, UID_Split_17>;
        unique_ptr<SplitterType_Split_17> splitter_Split_17_ptr (new SplitterType_Split_17(unionall_Extract_16_Split_17_connector, outputs, UID_Split_17, false));
        SplitterType_Split_17 * splitter_Split_17 = splitter_Split_17_ptr.get();

        if (argv != nullptr && argc > 0)
        {
            try
            {
                int sequenceNumber = GetSequenceNumber(argv, argc);
                splitter_Split_17->SetSequenceNumber(sequenceNumber);
            }
            catch(const RuntimeException&)
            {
                // Sequence number will remain 0 in splitter_Split_17.
            }
        }

        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *splitter_Split_17) };

        try
        {
            // Init operator chain
            splitter_Split_17->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_16_Data0 row;
            splitter_Split_17->GetNextRow(row);

            // Close operator chain
            splitter_Split_17->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        splitter_Split_17->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV4_Extract_Split
#pragma region SV5_Aggregate
#if defined(COMPILE_SV5_AGGREGATE) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<Part_GetSStream_0,UID_SStreamMetadataOutput_19>
    {
    public:
        struct KeyStruct
        {

            KeyStruct(Part_GetSStream_0 & c) 

            {
            }

            KeyStruct(const Part_GetSStream_0 & c, IncrementalAllocator * alloc) 

            {
            }

            KeyStruct(KeyStruct & c) 

            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) 

            {
            }

            KeyStruct() 

            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {
                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Part_GetSStream_0 & row, KeyType & key)
        {
            int r = 0;
            return r;
        }

        static int Compare(Part_GetSStream_0 * n1, Part_GetSStream_0 * n2)
        {
            int r = 0;
            return r;
        }

    };



#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV5_Agg : SStreamMetadataExtractor<Extract_16_Data0> { using SStreamMetadataExtractor<Extract_16_Data0>::SStreamMetadataExtractor; };
struct MetadataAggregateType_MetadataAggregate_18 : Merger<ExtractorType1_SV5_Agg, Extract_16_Data0, ScopeUnionAll<ExtractorType1_SV5_Agg, Extract_16_Data0>, UID_MetadataAggregate_18> { using Merger<ExtractorType1_SV5_Agg, Extract_16_Data0, ScopeUnionAll<ExtractorType1_SV5_Agg, Extract_16_Data0>, UID_MetadataAggregate_18>::Merger; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV5_Aggregate_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // remove the empty stream
        // For the case "PARTITION_NOT_EXIST", the output stream is blank. So here the input stream may be blank.
        int inputIdx2 = 0;
        
        for (int inputIdx = 0; inputIdx < inputCnt; ++inputIdx)
        {
            if(inputs[inputIdx].length == 0)
            {
                continue;
            }
            inputs[inputIdx2] = inputs[inputIdx];
            ++inputIdx2;
        }
        inputCnt =inputIdx2;

        // ExtractorType1_SV5_Agg: SStreamMetadataExtractor<Extract_16_Data0>
        unique_ptr<unique_ptr<ExtractorType1_SV5_Agg>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV5_Agg>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV5_Agg(inputs[i], i, false, false, UID_SV4_Extract_Split_out1));
        }

    ExtractorType1_SV5_Agg ** extractor_0 = (ExtractorType1_SV5_Agg **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // MetadataAggregateType_MetadataAggregate_18: Merger<ExtractorType1_SV5_Agg, Extract_16_Data0, ScopeUnionAll<ExtractorType1_SV5_Agg, Extract_16_Data0>, UID_MetadataAggregate_18>
        unique_ptr<MetadataAggregateType_MetadataAggregate_18> metadataAggregate_MetadataAggregate_18_ptr(new MetadataAggregateType_MetadataAggregate_18(extractor_0, extractor_0_count, false, UID_MetadataAggregate_18));
        MetadataAggregateType_MetadataAggregate_18* metadataAggregate_MetadataAggregate_18 = metadataAggregate_MetadataAggregate_18_ptr.get();

        using OutputterType2_SV5_Agg = SStreamMetadataOutputter<MetadataAggregateType_MetadataAggregate_18, Extract_16_Data0, Part_GetSStream_0, UID_SStreamMetadataOutput_19>;
        unique_ptr<OutputterType2_SV5_Agg> outputter_SStreamMetadataOutput_19_ptr(new OutputterType2_SV5_Agg(metadataAggregate_MetadataAggregate_18, outputs[0].outputFileName, "", false, false, 0, UID_SStreamMetadataOutput_19));
        OutputterType2_SV5_Agg * outputter_SStreamMetadataOutput_19 = outputter_SStreamMetadataOutput_19_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SStreamMetadataOutput_19) };

        try
        {
            // Init operator chain
            outputter_SStreamMetadataOutput_19->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_16_Data0 row;
            outputter_SStreamMetadataOutput_19->GetNextRow(row);

            // Close operator chain
            outputter_SStreamMetadataOutput_19->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SStreamMetadataOutput_19->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV5_Aggregate
#pragma region SV6_Extract
#if defined(COMPILE_SV6_EXTRACT) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<Extract_20_Data0,UID_Process_21>
    {
    public:
        struct KeyStruct
        {
            FString m_Region;

            KeyStruct(Extract_20_Data0 & c) :
                m_Region(c.m_Region)
            {
            }

            KeyStruct(const Extract_20_Data0 & c, IncrementalAllocator * alloc) :
                m_Region(const_cast<Extract_20_Data0&>(c).m_Region, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Region(c.m_Region)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Region(const_cast<KeyStruct&>(c).m_Region, alloc)
            {
            }

            KeyStruct() :
                m_Region()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Region:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Extract_20_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Region, key.m_Region)) != 0)
                return r;
            return r;
        }

        static int Compare(Extract_20_Data0 * n1, Extract_20_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Region, (*n2).m_Region)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Extract_20_Data0 * p, int depth)
        {
            if (depth < 1 && (*p).m_Region.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_Region.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_Region.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_Region.buffer()[depth]));
            }

            depth -= (int) ((*p).m_Region.size() + 1);


            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Extract_20_Data0 * p, int depth)
        {
            depth -= (int) ((*p).m_Region.size() + 1);
            if (depth < 0)
                return false;
            return true;
        }
    };



    static const char * StringTable_Process_22 [] =
    {
        "Region",
        "Duration",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_20_Data0, Process_22_Data0, UID_Process_22>
    {
    public:
        static bool FilterTransformRow(Extract_20_Data0 & input, Process_22_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_Region = input.m_Region;
                exceptionIndex++;
                output.m_TotalDuration = input.m_Duration;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_22[exceptionIndex]));
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


#if defined(COMPILE_NATIVE)
    template<> 
    class TextExtractPolicy<Extract_20_Data0, UID_Extract_20>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_20_Data0 & row)
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

                    input->SkipColumn();
                    input->SkipColumn();
                    input->Read(row.m_Region);
                    input->SkipColumn();
                    input->Read(row.m_Duration);
                    input->SkipColumn();
                    input->SkipColumn();

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
                            { input->CurrentLineNumber() - 1, 7, input->CurrentField() },
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
            static const std::array<const char*, 8> c_columnNames =
            {
                "UserId",
                "Start",
                "Region",
                "Query",
                "Duration",
                "Urls",
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


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<>
    class RowTransformPolicy<Process_22_Data0, Process_22_Data0, UID_Process_23>
    {
    public:
        static bool FilterTransformRow(Process_22_Data0 & input, Process_22_Data0 & output, IncrementalAllocator * alloc)
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
    struct ManagedUDO<UID_Process_23>
    {
        typedef ScopeRuntime::Processor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Process_23());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{})));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Process_23, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_Region_String_TotalDuration_Integer();
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
    class InteropToManagedRowPolicy<Process_22_Data0, UID_Process_23>
    {
    public:
        static void Marshal(Process_22_Data0& nativeRow, ScopeRuntime::Row^% managedRow, InteropAllocator * alloc)
        {
            alloc->CopyToManagedColumn(nativeRow.m_Region, managedRow[0], 0);
            alloc->CopyToManagedColumn(nativeRow.m_TotalDuration, managedRow[1], 1);
        }
    };
    template<>
    class InteropToNativeRowPolicy<Process_22_Data0, UID_Process_23>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Process_22_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Region, managedRow[0]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_TotalDuration, managedRow[1]->Integer, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Process_22_Data0, UID_SV6_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Process_22_Data0 & row)
        {
            if (!row.m_Region.IsNull())
            {
                output->Write<FString,false>(row.m_Region);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_TotalDuration);
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
struct ExtractorType1_SV6_Extr : Extractor<Extract_20_Data0, TextExtractPolicy<Extract_20_Data0, UID_Extract_20>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<Extract_20_Data0, TextExtractPolicy<Extract_20_Data0, UID_Extract_20>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct UnionAllType_Extract_20_Process_21_connector : ParallelUnionAll<ExtractorType1_SV6_Extr, Extract_20_Data0, false> { using ParallelUnionAll<ExtractorType1_SV6_Extr, Extract_20_Data0, false>::ParallelUnionAll; };
struct SorterType_Process_21 : Sorter<Extract_20_Data0> { using Sorter<Extract_20_Data0>::Sorter; };
struct FilterTransformerType_Process_22 : FilterTransformer<SorterType_Process_21, Extract_20_Data0, Process_22_Data0, UID_Process_22> { using FilterTransformer<SorterType_Process_21, Extract_20_Data0, Process_22_Data0, UID_Process_22>::FilterTransformer; };
struct ProcessorType_Process_23 : ScopeProcessor<Process_22_Data0, Process_22_Data0> { using ScopeProcessor<Process_22_Data0, Process_22_Data0>::ScopeProcessor; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV6_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV6_Extr: Extractor<Extract_20_Data0, TextExtractPolicy<Extract_20_Data0, UID_Extract_20>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV6_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV6_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV6_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_20));
        }

    ExtractorType1_SV6_Extr ** extractor_0 = (ExtractorType1_SV6_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_Extract_20_Process_21_connector: ParallelUnionAll<ExtractorType1_SV6_Extr, Extract_20_Data0, false>
        unique_ptr<UnionAllType_Extract_20_Process_21_connector> unionall_Extract_20_Process_21_connector_ptr(new UnionAllType_Extract_20_Process_21_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_20));
        UnionAllType_Extract_20_Process_21_connector * unionall_Extract_20_Process_21_connector = unionall_Extract_20_Process_21_connector_ptr.get();
        ULONG unionall_Extract_20_Process_21_connector_count = 1;
        unique_ptr<OperatorDelegate<Extract_20_Data0>> delegate_unionall_Extract_20_Process_21_connector_ptr (new OperatorDelegate<Extract_20_Data0>(unionall_Extract_20_Process_21_connector));
        OperatorDelegate<Extract_20_Data0> * delegate_unionall_Extract_20_Process_21_connector = delegate_unionall_Extract_20_Process_21_connector_ptr.get();
        ULONG delegate_unionall_Extract_20_Process_21_connector_count = 1;

        // SorterType_Process_21: Sorter<Extract_20_Data0>
        unique_ptr<SorterType_Process_21> sorter_Process_21_ptr (new SorterType_Process_21(delegate_unionall_Extract_20_Process_21_connector, &MKQSort<Extract_20_Data0>::Sort<KeyComparePolicy<Extract_20_Data0, UID_Process_21>, (sizeof(Extract_20_Data0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<Extract_20_Data0>::CreateDelegate<UID_Process_21>(), false, 2147483648 /*memoryQuota*/, UID_Process_21));
        SorterType_Process_21 * sorter_Process_21 = sorter_Process_21_ptr.get();
        ULONG sorter_Process_21_count = 1;

        // FilterTransformerType_Process_22: FilterTransformer<SorterType_Process_21, Extract_20_Data0, Process_22_Data0, UID_Process_22>
        unique_ptr<FilterTransformerType_Process_22> filterTransformer_Process_22_ptr (new FilterTransformerType_Process_22(sorter_Process_21, UID_Process_22));
        FilterTransformerType_Process_22 * filterTransformer_Process_22 = filterTransformer_Process_22_ptr.get();
        ULONG filterTransformer_Process_22_count = 1;
        unique_ptr<OperatorDelegate<Process_22_Data0>> delegate_filterTransformer_Process_22_ptr (new OperatorDelegate<Process_22_Data0>(filterTransformer_Process_22));
        OperatorDelegate<Process_22_Data0> * delegate_filterTransformer_Process_22 = delegate_filterTransformer_Process_22_ptr.get();
        ULONG delegate_filterTransformer_Process_22_count = 1;

        // ProcessorType_Process_23: ScopeProcessor<Process_22_Data0, Process_22_Data0>
        unique_ptr<ProcessorType_Process_23> processor_Process_23_ptr (new ProcessorType_Process_23(ScopeGrouperManagedFactory::Make<Process_22_Data0,Process_22_Data0,UID_Process_23>(delegate_filterTransformer_Process_22), delegate_filterTransformer_Process_22, UID_Process_23));
        ProcessorType_Process_23 * processor_Process_23 = processor_Process_23_ptr.get();
        ULONG processor_Process_23_count = 1;

        using OutputterType2_SV6_Extr = Outputter<ProcessorType_Process_23, Process_22_Data0, TextOutputPolicy<Process_22_Data0, UID_SV6_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV6_Extr> outputter_SV6_Extract_out0_ptr(new OutputterType2_SV6_Extr(processor_Process_23, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV6_Extract_out0));
        OutputterType2_SV6_Extr * outputter_SV6_Extract_out0 = outputter_SV6_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV6_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV6_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_22_Data0 row;
            outputter_SV6_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV6_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV6_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
template ScopeProcessorManaged<Process_22_Data0, Process_22_Data0> * ScopeEngine::ScopeGrouperManagedFactory::Make<Process_22_Data0, Process_22_Data0, UID_Process_23>(OperatorDelegate<Process_22_Data0>*);
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV6_Extract
#pragma region SV7_Extract
#if defined(COMPILE_SV7_EXTRACT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_MANAGED)
    template<>
    struct ManagedUDO<UID_Extract_25>
    {
        typedef ScopeRuntime::Extractor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Extract_25());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{})));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Extract_25, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_42AAB829FBD45C8D();
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
    class InteropToNativeRowSystemColumnPolicy<Extract_25_Data0, UID_Extract_25>
    {
    public:
        static void SetStreamIdSystemColumn(int streamId, Extract_25_Data0& nativeRow)
        {
            SCOPE_ASSERT(!"SetStreamIdSystemColumn method should not be invoked.");
        }
    };
    template<>
    class InteropToNativeRowPolicy<Extract_25_Data0, UID_Extract_25>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Extract_25_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_IId, managedRow[0]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Start, managedRow[1]->DateTime, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Market, managedRow[2]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Query, managedRow[3]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_DwellTime, managedRow[4]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Results, managedRow[5]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_ClickedUrls, managedRow[6]->Binary, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Extract_25_Data0, UID_SV7_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_25_Data0 & row)
        {
            output->Write<int,false>(row.m_IId);
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



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV7_Extr : ScopeExtractor<CosmosInput, Extract_25_Data0, -1> { using ScopeExtractor<CosmosInput, Extract_25_Data0, -1>::ScopeExtractor; };
struct UnionAllType_Extract_25_SV7_Extract_out0_connector : ParallelUnionAll<ExtractorType1_SV7_Extr, Extract_25_Data0, false> { using ParallelUnionAll<ExtractorType1_SV7_Extr, Extract_25_Data0, false>::ParallelUnionAll; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV7_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV7_Extr: ScopeExtractor<CosmosInput, Extract_25_Data0, -1>
        unique_ptr<unique_ptr<ExtractorType1_SV7_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV7_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV7_Extr(ScopeExtractorManagedFactory::Make<CosmosInput,Extract_25_Data0,UID_Extract_25, 0>(argv, argc), inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_Extract_25));
        }

    ExtractorType1_SV7_Extr ** extractor_0 = (ExtractorType1_SV7_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_Extract_25_SV7_Extract_out0_connector: ParallelUnionAll<ExtractorType1_SV7_Extr, Extract_25_Data0, false>
        unique_ptr<UnionAllType_Extract_25_SV7_Extract_out0_connector> unionall_Extract_25_SV7_Extract_out0_connector_ptr(new UnionAllType_Extract_25_SV7_Extract_out0_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_25));
        UnionAllType_Extract_25_SV7_Extract_out0_connector * unionall_Extract_25_SV7_Extract_out0_connector = unionall_Extract_25_SV7_Extract_out0_connector_ptr.get();
        ULONG unionall_Extract_25_SV7_Extract_out0_connector_count = 1;

        using OutputterType2_SV7_Extr = Outputter<UnionAllType_Extract_25_SV7_Extract_out0_connector, Extract_25_Data0, TextOutputPolicy<Extract_25_Data0, UID_SV7_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV7_Extr> outputter_SV7_Extract_out0_ptr(new OutputterType2_SV7_Extr(unionall_Extract_25_SV7_Extract_out0_connector, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV7_Extract_out0));
        OutputterType2_SV7_Extr * outputter_SV7_Extract_out0 = outputter_SV7_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV7_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV7_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_25_Data0 row;
            outputter_SV7_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV7_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV7_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
template ScopeExtractorManaged<CosmosInput,Extract_25_Data0> * ScopeEngine::ScopeExtractorManagedFactory::Make<CosmosInput, Extract_25_Data0, UID_Extract_25, 0>(std::string * argv, int argc);
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV7_Extract
#pragma region SV8_Extract
#if defined(COMPILE_SV8_EXTRACT) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<Extract_27_Data0,UID_Process_28>
    {
    public:
        struct KeyStruct
        {
            FString m_Name;

            KeyStruct(Extract_27_Data0 & c) :
                m_Name(c.m_Name)
            {
            }

            KeyStruct(const Extract_27_Data0 & c, IncrementalAllocator * alloc) :
                m_Name(const_cast<Extract_27_Data0&>(c).m_Name, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Name(c.m_Name)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Name(const_cast<KeyStruct&>(c).m_Name, alloc)
            {
            }

            KeyStruct() :
                m_Name()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Name:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Extract_27_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Name, key.m_Name)) != 0)
                return r;
            return r;
        }

        static int Compare(Extract_27_Data0 * n1, Extract_27_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Name, (*n2).m_Name)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Extract_27_Data0 * p, int depth)
        {
            if (depth < 1 && (*p).m_Name.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_Name.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_Name.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_Name.buffer()[depth]));
            }

            depth -= (int) ((*p).m_Name.size() + 1);


            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Extract_27_Data0 * p, int depth)
        {
            depth -= (int) ((*p).m_Name.size() + 1);
            if (depth < 0)
                return false;
            return true;
        }
    };




#if defined(COMPILE_NATIVE)
    template<> 
    class TextExtractPolicy<Extract_27_Data0, UID_Extract_27>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<',', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_27_Data0 & row)
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

                    input->Read(row.m_SepalLength);
                    input->Read(row.m_SepalWidth);
                    input->Read(row.m_PetalLength);
                    input->Read(row.m_PetalWidth);
                    input->Read(row.m_Name);

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
                            { input->CurrentLineNumber() - 1, 5, input->CurrentField() },
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
            static const std::array<const char*, 6> c_columnNames =
            {
                "SepalLength",
                "SepalWidth",
                "PetalLength",
                "PetalWidth",
                "Name",
                "*** END ***"
            };

            auto idx = std::min(columnIndex, c_columnNames.size() - 1);
            return c_columnNames[idx];
        }
    };

#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<> 
    class KeyComparePolicy<Extract_27_Data0,UID_Process_29>
    {
    public:
        struct KeyStruct
        {
            FString m_Name;

            KeyStruct(Extract_27_Data0 & c) :
                m_Name(c.m_Name)
            {
            }

            KeyStruct(const Extract_27_Data0 & c, IncrementalAllocator * alloc) :
                m_Name(const_cast<Extract_27_Data0&>(c).m_Name, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Name(c.m_Name)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Name(const_cast<KeyStruct&>(c).m_Name, alloc)
            {
            }

            KeyStruct() :
                m_Name()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Name:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Extract_27_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Name, key.m_Name)) != 0)
                return r;
            return r;
        }

        static int Compare(Extract_27_Data0 * n1, Extract_27_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Name, (*n2).m_Name)) != 0)
                return r;
            return r;
        }

    };




    template<>
    class RowTransformPolicy<Extract_27_Data0, Process_29_Data0, UID_Process_29>
    {
    public:
        static bool FilterTransformRow(Extract_27_Data0 & input, Process_29_Data0 & output, IncrementalAllocator * alloc)
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
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<>
    class AdapterToHostRowCopyPolicy<Extract_27_Data0, Process_29_Data0, UID_Process_29>
    {
    public:
        static void CopyInputRow(Extract_27_Data0& inputRow, Process_29_Data0& outputRow, IncrementalAllocator& alloc)
        {
                throw ProxyHostRuntimeException(E_COPY_FROM_INPUT_ROW_NOT_SUPPORTED, {});
        }

        static void MarshalUdoRow(const IRowDataReader& udoRow, Process_29_Data0& outputRow, const ProxyHostPassTroughRow<Process_29_Data0>& passThroughRow, IncrementalAllocator& alloc)
        {
            if (udoRow.HasValue(0))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(0, columnData);
                if (columnData.m_type != USqlColumnType::Double)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {0, USqlColumnTypeTraits<USqlColumnType::Double>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {0, USqlColumnTypeTraits<USqlColumnType::Double>::typeName});
                    outputRow.m_SepalLength_Mean = columnData.GetData<double>();
            }
            else if (passThroughRow.HasValue(0))
                outputRow.m_SepalLength_Mean = passThroughRow.GetRuntimeRow().m_SepalLength_Mean;
            else
                ProxyColumnTypeTraits<double>::SetDefault(outputRow.m_SepalLength_Mean);
            if (udoRow.HasValue(1))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(1, columnData);
                if (columnData.m_type != USqlColumnType::Double)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {1, USqlColumnTypeTraits<USqlColumnType::Double>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {1, USqlColumnTypeTraits<USqlColumnType::Double>::typeName});
                    outputRow.m_SepalWidth_Mean = columnData.GetData<double>();
            }
            else if (passThroughRow.HasValue(1))
                outputRow.m_SepalWidth_Mean = passThroughRow.GetRuntimeRow().m_SepalWidth_Mean;
            else
                ProxyColumnTypeTraits<double>::SetDefault(outputRow.m_SepalWidth_Mean);
            if (udoRow.HasValue(2))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(2, columnData);
                if (columnData.m_type != USqlColumnType::Double)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {2, USqlColumnTypeTraits<USqlColumnType::Double>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {2, USqlColumnTypeTraits<USqlColumnType::Double>::typeName});
                    outputRow.m_PetalLength_Mean = columnData.GetData<double>();
            }
            else if (passThroughRow.HasValue(2))
                outputRow.m_PetalLength_Mean = passThroughRow.GetRuntimeRow().m_PetalLength_Mean;
            else
                ProxyColumnTypeTraits<double>::SetDefault(outputRow.m_PetalLength_Mean);
            if (udoRow.HasValue(3))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(3, columnData);
                if (columnData.m_type != USqlColumnType::Double)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {3, USqlColumnTypeTraits<USqlColumnType::Double>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {3, USqlColumnTypeTraits<USqlColumnType::Double>::typeName});
                    outputRow.m_PetalWidth_Mean = columnData.GetData<double>();
            }
            else if (passThroughRow.HasValue(3))
                outputRow.m_PetalWidth_Mean = passThroughRow.GetRuntimeRow().m_PetalWidth_Mean;
            else
                ProxyColumnTypeTraits<double>::SetDefault(outputRow.m_PetalWidth_Mean);
            if (udoRow.HasValue(4))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Name);
                udoRow.Get(4, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {4, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else if (passThroughRow.HasValue(4))
                outputRow.m_Name = passThroughRow.GetRuntimeRow().m_Name;
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Name);

            if (udoRow.HasValue(5))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(5, columnData);
                if (columnData.m_type != USqlColumnType::Integer)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {5, USqlColumnTypeTraits<USqlColumnType::Integer>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {5, USqlColumnTypeTraits<USqlColumnType::Integer>::typeName});
                    outputRow.m_Count = columnData.GetData<int>();
            }
            else if (passThroughRow.HasValue(5))
                outputRow.m_Count = passThroughRow.GetRuntimeRow().m_Count;
            else
                ProxyColumnTypeTraits<int>::SetDefault(outputRow.m_Count);
        }

        static const std::vector<columnIndex_t> OutputReadOnlyColumns()
        {
            return std::vector<columnIndex_t> {};
        }

        static const std::vector<columnIndex_t> InputReadOnlyColumns()
        {
            return std::vector<columnIndex_t> {};
        }

        static void CopyReadOnlyColumns(Extract_27_Data0& inputRow, Process_29_Data0& outputRow, IncrementalAllocator& alloc)
        {
        } 

    };
#endif // defined(COMPILE_NATIVE)



    template<> 
    class TextOutputPolicy<Process_29_Data0, UID_SV8_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Process_29_Data0 & row)
        {
            output->Write<double,false>(row.m_SepalLength_Mean);
            output->WriteDelimiter();
            output->Write<double,false>(row.m_SepalWidth_Mean);
            output->WriteDelimiter();
            output->Write<double,false>(row.m_PetalLength_Mean);
            output->WriteDelimiter();
            output->Write<double,false>(row.m_PetalWidth_Mean);
            output->WriteDelimiter();
            if (!row.m_Name.IsNull())
            {
                output->Write<FString,false>(row.m_Name);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Count);
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV8_Extr : Extractor<Extract_27_Data0, TextExtractPolicy<Extract_27_Data0, UID_Extract_27>, TextInputStream<TextInputStreamTraitsConst<',', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<Extract_27_Data0, TextExtractPolicy<Extract_27_Data0, UID_Extract_27>, TextInputStream<TextInputStreamTraitsConst<',', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct UnionAllType_Extract_27_Process_28_connector : ParallelUnionAll<ExtractorType1_SV8_Extr, Extract_27_Data0, false> { using ParallelUnionAll<ExtractorType1_SV8_Extr, Extract_27_Data0, false>::ParallelUnionAll; };
struct SorterType_Process_28 : Sorter<Extract_27_Data0> { using Sorter<Extract_27_Data0>::Sorter; };
struct ReducerType_Process_29 : ScopeProcessor<Extract_27_Data0, Process_29_Data0> { using ScopeProcessor<Extract_27_Data0, Process_29_Data0>::ScopeProcessor; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV8_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        // load UDO adapter plugin dlls
        constexpr int maxFilePath = 1024;
        char path[maxFilePath + 20];
        size_t pathSize = LoadedImage::GetEngineDirectory(path, maxFilePath);
        ProxyHostEnvironmentHelper::CreateInstance(path);

        strcpy_s(path + pathSize, sizeof(path) - pathSize, "PythonUdoAdapter.dll");
        shared_ptr<LoadedImage> pythonPluginDll = LoadedImage::LoadFromFile(path);
        CreateUdoFactory pythonEntryMethod = (CreateUdoFactory)pythonPluginDll->GetProcAddress("CreateUdoFactory", TRUE);
        ProxyHostEnvironment pythonHostEnvironment(ProxyHostEnvironmentHelper::GetInstance(), 1283457024);
        IAdapterUdoFactory* pythonUdoFactory = GuardAdapterCode ([pythonEntryMethod, &pythonHostEnvironment]()
        {
            return pythonEntryMethod(pythonHostEnvironment);
        });
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV8_Extr: Extractor<Extract_27_Data0, TextExtractPolicy<Extract_27_Data0, UID_Extract_27>, TextInputStream<TextInputStreamTraitsConst<',', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV8_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV8_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV8_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters(',', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_27));
        }

    ExtractorType1_SV8_Extr ** extractor_0 = (ExtractorType1_SV8_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_Extract_27_Process_28_connector: ParallelUnionAll<ExtractorType1_SV8_Extr, Extract_27_Data0, false>
        unique_ptr<UnionAllType_Extract_27_Process_28_connector> unionall_Extract_27_Process_28_connector_ptr(new UnionAllType_Extract_27_Process_28_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_27));
        UnionAllType_Extract_27_Process_28_connector * unionall_Extract_27_Process_28_connector = unionall_Extract_27_Process_28_connector_ptr.get();
        ULONG unionall_Extract_27_Process_28_connector_count = 1;
        unique_ptr<OperatorDelegate<Extract_27_Data0>> delegate_unionall_Extract_27_Process_28_connector_ptr (new OperatorDelegate<Extract_27_Data0>(unionall_Extract_27_Process_28_connector));
        OperatorDelegate<Extract_27_Data0> * delegate_unionall_Extract_27_Process_28_connector = delegate_unionall_Extract_27_Process_28_connector_ptr.get();
        ULONG delegate_unionall_Extract_27_Process_28_connector_count = 1;

        // SorterType_Process_28: Sorter<Extract_27_Data0>
        unique_ptr<SorterType_Process_28> sorter_Process_28_ptr (new SorterType_Process_28(delegate_unionall_Extract_27_Process_28_connector, &MKQSort<Extract_27_Data0>::Sort<KeyComparePolicy<Extract_27_Data0, UID_Process_28>, (sizeof(Extract_27_Data0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<Extract_27_Data0>::CreateDelegate<UID_Process_28>(), false, 2147483648 /*memoryQuota*/, UID_Process_28));
        SorterType_Process_28 * sorter_Process_28 = sorter_Process_28_ptr.get();
        ULONG sorter_Process_28_count = 1;
        unique_ptr<OperatorDelegate<Extract_27_Data0>> delegate_sorter_Process_28_ptr (new OperatorDelegate<Extract_27_Data0>(sorter_Process_28));
        OperatorDelegate<Extract_27_Data0> * delegate_sorter_Process_28 = delegate_sorter_Process_28_ptr.get();
        ULONG delegate_sorter_Process_28_count = 1;

        // ReducerType_Process_29: ScopeProcessor<Extract_27_Data0, Process_29_Data0>
            ProxyHostUdoCreationCodeEvaluation pythonCreationArgs_UID_Process_29("import Scope1", "Scope1.DataFrameDemoReducer()");
            IAdapterReducer& pythonReducer_UID_Process_29 = GuardAdapterCode([pythonUdoFactory, &pythonCreationArgs_UID_Process_29]() -> IAdapterReducer&
            {
                return pythonUdoFactory->CreateReducer(pythonCreationArgs_UID_Process_29);
            });
        unique_ptr<ReducerType_Process_29> reducer_Process_29_ptr (new ReducerType_Process_29(ScopeReducerManagedFactory::MakeAdapter<Extract_27_Data0,Process_29_Data0,ReduceKey_Process_29,UID_Process_29>(pythonReducer_UID_Process_29, delegate_sorter_Process_28), delegate_sorter_Process_28, UID_Process_29));
        ReducerType_Process_29 * reducer_Process_29 = reducer_Process_29_ptr.get();
        ULONG reducer_Process_29_count = 1;

        using OutputterType2_SV8_Extr = Outputter<ReducerType_Process_29, Process_29_Data0, TextOutputPolicy<Process_29_Data0, UID_SV8_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV8_Extr> outputter_SV8_Extract_out0_ptr(new OutputterType2_SV8_Extr(reducer_Process_29, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters(',', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV8_Extract_out0));
        OutputterType2_SV8_Extr * outputter_SV8_Extract_out0 = outputter_SV8_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV8_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV8_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_29_Data0 row;
            outputter_SV8_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV8_Extract_out0->Close();

            // release UDO adapter factories
            pythonUdoFactory->Release();

            // reset UDO adapter host environment
            g_udoAdapterHostEnvironment->Release();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV8_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
template ScopeProcessorManaged<Extract_27_Data0, Process_29_Data0> * ScopeEngine::ScopeReducerManagedFactory::MakeAdapter<Extract_27_Data0, Process_29_Data0,ReduceKey_Process_29, UID_Process_29>(IAdapterReducer&, OperatorDelegate<Extract_27_Data0>*);
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV8_Extract
#pragma region SV9_Extract
#if defined(COMPILE_SV9_EXTRACT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<>
    class AdapterExtractorToHostRowCopyPolicy<Extract_31_Data0, UID_Extract_31>
    {
    public:
        static void MarshalUdoRow(const IAdapterUdoRow& udoRow, Extract_31_Data0& outputRow, IncrementalAllocator& alloc)
        {
            if (udoRow.HasValue(0))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_UserId);
                udoRow.Get(0, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {0, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_UserId);

            if (udoRow.HasValue(1))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Start);
                udoRow.Get(1, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {1, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Start);

            if (udoRow.HasValue(2))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Region);
                udoRow.Get(2, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {2, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Region);

            if (udoRow.HasValue(3))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Query);
                udoRow.Get(3, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {3, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Query);

            if (udoRow.HasValue(4))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Duration);
                udoRow.Get(4, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {4, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Duration);

            if (udoRow.HasValue(5))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Urls);
                udoRow.Get(5, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {5, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Urls);

            if (udoRow.HasValue(6))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_ClickedUrls);
                udoRow.Get(6, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {6, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_ClickedUrls);

        }
    };
#endif // defined(COMPILE_NATIVE)



    template<> 
    class TextOutputPolicy<Extract_31_Data0, UID_SV9_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_31_Data0 & row)
        {
            if (!row.m_UserId.IsNull())
            {
                output->Write<FString,false>(row.m_UserId);
            }
            output->WriteDelimiter();
            if (!row.m_Start.IsNull())
            {
                output->Write<FString,false>(row.m_Start);
            }
            output->WriteDelimiter();
            if (!row.m_Region.IsNull())
            {
                output->Write<FString,false>(row.m_Region);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            if (!row.m_Duration.IsNull())
            {
                output->Write<FString,false>(row.m_Duration);
            }
            output->WriteDelimiter();
            if (!row.m_Urls.IsNull())
            {
                output->Write<FString,false>(row.m_Urls);
            }
            output->WriteDelimiter();
            if (!row.m_ClickedUrls.IsNull())
            {
                output->Write<FString,false>(row.m_ClickedUrls);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV9_Extr : ScopeExtractor<CosmosInput, Extract_31_Data0, -1> { using ScopeExtractor<CosmosInput, Extract_31_Data0, -1>::ScopeExtractor; };
struct UnionAllType_extractor_serially_Extract_31_connector : RestrictedUnionAllMerger<ExtractorType1_SV9_Extr, Extract_31_Data0> { using RestrictedUnionAllMerger<ExtractorType1_SV9_Extr, Extract_31_Data0>::RestrictedUnionAllMerger; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV9_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        // load UDO adapter plugin dlls
        constexpr int maxFilePath = 1024;
        char path[maxFilePath + 20];
        size_t pathSize = LoadedImage::GetEngineDirectory(path, maxFilePath);
        ProxyHostEnvironmentHelper::CreateInstance(path);

        strcpy_s(path + pathSize, sizeof(path) - pathSize, "PythonUdoAdapter.dll");
        shared_ptr<LoadedImage> pythonPluginDll = LoadedImage::LoadFromFile(path);
        CreateUdoFactory pythonEntryMethod = (CreateUdoFactory)pythonPluginDll->GetProcAddress("CreateUdoFactory", TRUE);
        ProxyHostEnvironment pythonHostEnvironment(ProxyHostEnvironmentHelper::GetInstance(), 1283457024);
        IAdapterUdoFactory* pythonUdoFactory = GuardAdapterCode ([pythonEntryMethod, &pythonHostEnvironment]()
        {
            return pythonEntryMethod(pythonHostEnvironment);
        });
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV9_Extr: ScopeExtractor<CosmosInput, Extract_31_Data0, -1>
        unique_ptr<unique_ptr<ExtractorType1_SV9_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV9_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            ProxyHostUdoCreationCodeEvaluation pythonCreationArgs_UID_Extract_31("import Scope1", "Scope1.SearchLogExtractor()");
            IAdapterExtractor& pythonExtractor_UID_Extract_31 = GuardAdapterCode([pythonUdoFactory, &pythonCreationArgs_UID_Extract_31]() -> IAdapterExtractor&
            {
                return pythonUdoFactory->CreateExtractor(pythonCreationArgs_UID_Extract_31);
            });
            extractor_0_array[i - 0].reset(new ExtractorType1_SV9_Extr(ScopeExtractorManagedFactory::MakeAdapter<CosmosInput,Extract_31_Data0,UID_Extract_31, 0>(pythonExtractor_UID_Extract_31), inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_Extract_31));
        }

    ExtractorType1_SV9_Extr ** extractor_0 = (ExtractorType1_SV9_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_extractor_serially_Extract_31_connector: RestrictedUnionAllMerger<ExtractorType1_SV9_Extr, Extract_31_Data0>
        unique_ptr<UnionAllType_extractor_serially_Extract_31_connector> unionall_extractor_serially_Extract_31_connector_ptr(new UnionAllType_extractor_serially_Extract_31_connector(extractor_0,extractor_0_count,1,1,UID_ParallelUnionAll_Extract_31));
        UnionAllType_extractor_serially_Extract_31_connector * unionall_extractor_serially_Extract_31_connector = unionall_extractor_serially_Extract_31_connector_ptr.get();
        ULONG unionall_extractor_serially_Extract_31_connector_count = 1;

        using OutputterType2_SV9_Extr = Outputter<UnionAllType_extractor_serially_Extract_31_connector, Extract_31_Data0, TextOutputPolicy<Extract_31_Data0, UID_SV9_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV9_Extr> outputter_SV9_Extract_out0_ptr(new OutputterType2_SV9_Extr(unionall_extractor_serially_Extract_31_connector, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters(',', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV9_Extract_out0));
        OutputterType2_SV9_Extr * outputter_SV9_Extract_out0 = outputter_SV9_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV9_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV9_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_31_Data0 row;
            outputter_SV9_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV9_Extract_out0->Close();

            // release UDO adapter factories
            pythonUdoFactory->Release();

            // reset UDO adapter host environment
            g_udoAdapterHostEnvironment->Release();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV9_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
template ScopeExtractorManaged<CosmosInput,Extract_31_Data0> * ScopeEngine::ScopeExtractorManagedFactory::MakeAdapter<CosmosInput, Extract_31_Data0, UID_Extract_31, 0>(IAdapterExtractor&);
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV9_Extract
#pragma region SV10_Extract
#if defined(COMPILE_SV10_EXTRACT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_NATIVE)
    template<> 
    class TextExtractPolicy<Extract_33_Data0, UID_Extract_33>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_33_Data0 & row)
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

                    input->Read(row.m_Id);
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
                            { input->CurrentLineNumber() - 1, 7, input->CurrentField() },
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
            static const std::array<const char*, 8> c_columnNames =
            {
                "Id",
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
    class TextOutputPolicy<Extract_33_Data0, UID_SV10_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_33_Data0 & row)
        {
            output->Write<int,false>(row.m_Id);
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



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV10_Extr : Extractor<Extract_33_Data0, TextExtractPolicy<Extract_33_Data0, UID_Extract_33>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<Extract_33_Data0, TextExtractPolicy<Extract_33_Data0, UID_Extract_33>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct UnionAllType_Extract_33_SV10_Extract_out0_connector : ParallelUnionAll<ExtractorType1_SV10_Extr, Extract_33_Data0, true> { using ParallelUnionAll<ExtractorType1_SV10_Extr, Extract_33_Data0, true>::ParallelUnionAll; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV10_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV10_Extr: Extractor<Extract_33_Data0, TextExtractPolicy<Extract_33_Data0, UID_Extract_33>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV10_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV10_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV10_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_33));
        }

    ExtractorType1_SV10_Extr ** extractor_0 = (ExtractorType1_SV10_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_Extract_33_SV10_Extract_out0_connector: ParallelUnionAll<ExtractorType1_SV10_Extr, Extract_33_Data0, true>
        unique_ptr<UnionAllType_Extract_33_SV10_Extract_out0_connector> unionall_Extract_33_SV10_Extract_out0_connector_ptr(new UnionAllType_Extract_33_SV10_Extract_out0_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_33));
        UnionAllType_Extract_33_SV10_Extract_out0_connector * unionall_Extract_33_SV10_Extract_out0_connector = unionall_Extract_33_SV10_Extract_out0_connector_ptr.get();
        ULONG unionall_Extract_33_SV10_Extract_out0_connector_count = 1;

        using OutputterType2_SV10_Extr = Outputter<UnionAllType_Extract_33_SV10_Extract_out0_connector, Extract_33_Data0, TextOutputPolicy<Extract_33_Data0, UID_SV10_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV10_Extr> outputter_SV10_Extract_out0_ptr(new OutputterType2_SV10_Extr(unionall_Extract_33_SV10_Extract_out0_connector, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV10_Extract_out0));
        OutputterType2_SV10_Extr * outputter_SV10_Extract_out0 = outputter_SV10_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV10_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV10_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_33_Data0 row;
            outputter_SV10_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV10_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV10_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV10_Extract
#pragma region SV11_Extract
#if defined(COMPILE_SV11_EXTRACT) || defined(COMPILE_ALL_VERTICES)


    template<>
    class RowTransformPolicy<Extract_38_Data0, Process_39_Data0, UID_Process_39>
    {
    public:
        static bool FilterTransformRow(Extract_38_Data0 & input, Process_39_Data0 & output, IncrementalAllocator * alloc)
        {
           output.m_Start = input.m_Start;
           output.m_Market = input.m_Market;
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
    struct ManagedUDO<UID_Process_39>
    {
        typedef ScopeRuntime::Processor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Process_39());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{})));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Process_39, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_Start_DateTime_Market_String_DwellTimeInMinutes_Double();
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
    class InteropToManagedRowPolicy<Extract_38_Data0, UID_Process_39>
    {
    public:
        static void Marshal(Extract_38_Data0& nativeRow, ScopeRuntime::Row^% managedRow, InteropAllocator * alloc)
        {
            alloc->CopyToManagedColumn(nativeRow.m_DwellTime, managedRow[2], 2);
        }
    };
    template<>
    class InteropToNativeRowPolicy<Process_39_Data0, UID_Process_39>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Process_39_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_DwellTimeInMinutes, managedRow[2]->Double, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<> 
    class TextExtractPolicy<Extract_38_Data0, UID_Extract_38>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_38_Data0 & row)
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

                    input->SkipColumn();
                    input->Read(row.m_Start);
                    input->Read(row.m_Market);
                    input->SkipColumn();
                    input->Read(row.m_DwellTime);
                    input->SkipColumn();
                    input->SkipColumn();

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
                            { input->CurrentLineNumber() - 1, 7, input->CurrentField() },
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
            static const std::array<const char*, 8> c_columnNames =
            {
                "IId",
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
    class TextOutputPolicy<Process_39_Data0, UID_SV11_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Process_39_Data0 & row)
        {
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Market.IsNull())
            {
                output->Write<FString,false>(row.m_Market);
            }
            output->WriteDelimiter();
            output->Write<double,false>(row.m_DwellTimeInMinutes);
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
struct ExtractorType1_SV11_Extr : Extractor<Extract_38_Data0, TextExtractPolicy<Extract_38_Data0, UID_Extract_38>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<Extract_38_Data0, TextExtractPolicy<Extract_38_Data0, UID_Extract_38>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct UnionAllType_Extract_38_Process_39_connector : ParallelUnionAll<ExtractorType1_SV11_Extr, Extract_38_Data0, false> { using ParallelUnionAll<ExtractorType1_SV11_Extr, Extract_38_Data0, false>::ParallelUnionAll; };
struct ProcessorType_Process_39 : ScopeProcessor<Extract_38_Data0, Process_39_Data0> { using ScopeProcessor<Extract_38_Data0, Process_39_Data0>::ScopeProcessor; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV11_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV11_Extr: Extractor<Extract_38_Data0, TextExtractPolicy<Extract_38_Data0, UID_Extract_38>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV11_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV11_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV11_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_38));
        }

    ExtractorType1_SV11_Extr ** extractor_0 = (ExtractorType1_SV11_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_Extract_38_Process_39_connector: ParallelUnionAll<ExtractorType1_SV11_Extr, Extract_38_Data0, false>
        unique_ptr<UnionAllType_Extract_38_Process_39_connector> unionall_Extract_38_Process_39_connector_ptr(new UnionAllType_Extract_38_Process_39_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_38));
        UnionAllType_Extract_38_Process_39_connector * unionall_Extract_38_Process_39_connector = unionall_Extract_38_Process_39_connector_ptr.get();
        ULONG unionall_Extract_38_Process_39_connector_count = 1;
        unique_ptr<OperatorDelegate<Extract_38_Data0>> delegate_unionall_Extract_38_Process_39_connector_ptr (new OperatorDelegate<Extract_38_Data0>(unionall_Extract_38_Process_39_connector));
        OperatorDelegate<Extract_38_Data0> * delegate_unionall_Extract_38_Process_39_connector = delegate_unionall_Extract_38_Process_39_connector_ptr.get();
        ULONG delegate_unionall_Extract_38_Process_39_connector_count = 1;

        // ProcessorType_Process_39: ScopeProcessor<Extract_38_Data0, Process_39_Data0>
        unique_ptr<ProcessorType_Process_39> processor_Process_39_ptr (new ProcessorType_Process_39(ScopeProcessorManagedFactory::Make<Extract_38_Data0,Process_39_Data0,UID_Process_39>(delegate_unionall_Extract_38_Process_39_connector), delegate_unionall_Extract_38_Process_39_connector, UID_Process_39));
        ProcessorType_Process_39 * processor_Process_39 = processor_Process_39_ptr.get();
        ULONG processor_Process_39_count = 1;

        using OutputterType2_SV11_Extr = Outputter<ProcessorType_Process_39, Process_39_Data0, TextOutputPolicy<Process_39_Data0, UID_SV11_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV11_Extr> outputter_SV11_Extract_out0_ptr(new OutputterType2_SV11_Extr(processor_Process_39, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV11_Extract_out0));
        OutputterType2_SV11_Extr * outputter_SV11_Extract_out0 = outputter_SV11_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV11_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV11_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_39_Data0 row;
            outputter_SV11_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV11_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV11_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
template ScopeProcessorManaged<Extract_38_Data0, Process_39_Data0> * ScopeEngine::ScopeProcessorManagedFactory::Make<Extract_38_Data0, Process_39_Data0, UID_Process_39>(OperatorDelegate<Extract_38_Data0>*);
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV11_Extract
#pragma region SV12_Extract_Combine
#if defined(COMPILE_SV12_EXTRACT_COMBINE) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_NATIVE)
    template<> 
    class SStreamV3ExtractPolicy<GetSStream_5_Data0, UID_GetSStream_5, NullSchema>
    {
    public:
        typedef NullSchema CorrelatedParameters;
        typedef bool (*PredFn)(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, CorrelatedParameters* params);

    public:
        typedef GetSStream_5_Data0 DataRowSchema;
        typedef Part_GetSStream_0 PartitionSchema;
        typedef Part_GetSStream_0 DataKeySchema;
        typedef RowComparePolicy<DataKeySchema, DataKeySchema, UID_GetSStream_5> DataKeyComparePolicy;
        typedef ResourceInputStream SystemResourceInputStream;

        static constexpr PartitioningType m_partitioning = RandomPartition;
        static constexpr bool m_residualFilterForKeyRange = false;
        static constexpr bool m_residualFilterForRefinedHash = false;
        static constexpr int  m_numberOfPartitionAfterRefinedHash = 0;
        static constexpr bool m_keyRangeSeek = false;
        static constexpr bool m_truncatedRangeKey = false;
        static constexpr bool m_readSelectedKeyRangesOnly = true;
        static constexpr bool m_generateMetadata = false;
        static constexpr UINT m_numOfBuffers = 4;
        static constexpr bool m_hasCorrelatedSchema = false;

        // FailFastSStreamRead ignores the maxUnavailability value and forces a fast failure in case of store errors
        static constexpr bool m_skipUnavailable = true; // MaxPercentInputUnavailability = 100

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>BingAdsUserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>MsAlias</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>UcmUserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>NumofMonth</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>LastMonth</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>TotalUsage</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static BYTE* DataColumnSizes()
        {
            static BYTE sizes[] = 
            {
                4,
                0,
                4,
                4,
                0,
                4,
            };

            return sizes;
        }
        static constexpr UINT m_dataColumnSizesCnt = 6;

        static BYTE* IndexColumnSizes()
        {
            static BYTE sizes[] = 
                {
                // Low key
                // Hi Key
                8, // BlockOffset
                8, // BlockLength
                4, // RowCount
                };

            return sizes;
        }
        static constexpr UINT m_indexColumnSizesCnt = 2 * 0 + 3;

        static UINT* SortKeys() { return nullptr; }
        static constexpr UINT m_sortKeysCnt = 0;

        static constexpr bool m_descending = false;


        static bool Deserialize(SSLibV3::ColumnIterator* iters, DataRowSchema & row, IncrementalAllocator* alloc, const BYTE* blockEnd, UINT32 defaultDistributionId, UINT64 defaultRowId)
        {
            STRUCTURED_DATA_ASSERT(iters[0].HasData(blockEnd));
            row.m_BingAdsUserId = iters[0].Data<int>();
            STRUCTURED_DATA_ASSERT(iters[1].HasData(blockEnd));
            if (iters[1].IsNull())
            {
                row.m_MsAlias.SetNull();
            }
            else
            {
                row.m_MsAlias.CopyFromNotNull((FString::PointerType)iters[1].DataRaw(), (int)iters[1].Length(), alloc);
            }
            STRUCTURED_DATA_ASSERT(iters[2].HasData(blockEnd));
            row.m_UcmUserId = iters[2].Data<int>();
            STRUCTURED_DATA_ASSERT(iters[3].HasData(blockEnd));
            row.m_NumofMonth = iters[3].Data<int>();
            STRUCTURED_DATA_ASSERT(iters[4].HasData(blockEnd));
            if (iters[4].IsNull())
            {
                row.m_LastMonth.SetNull();
            }
            else
            {
                row.m_LastMonth.CopyFromNotNull((FString::PointerType)iters[4].DataRaw(), (int)iters[4].Length(), alloc);
            }
            STRUCTURED_DATA_ASSERT(iters[5].HasData(blockEnd));
            row.m_TotalUsage = iters[5].Data<int>();
            return true;
        }

        static void SkipRow(SSLibV3::ColumnIterator* iters)
        {
            iters[0].IncrementFixedNotNullable<4>();
            if (iters[1].IsNull())
            {
                iters[1].IncrementNull();
            }
            else
            {
                iters[1].IncrementVariable();
            }
            iters[2].IncrementFixedNotNullable<4>();
            iters[3].IncrementFixedNotNullable<4>();
            if (iters[4].IsNull())
            {
                iters[4].IncrementNull();
            }
            else
            {
                iters[4].IncrementVariable();
            }
            iters[5].IncrementFixedNotNullable<4>();
            //// Section of the Partition Key iterators skip.
            //// Section of the System column iterators skip.
        }

        //// The deserialize method that extract Partition Key values without advance any of the iterators.
        static UINT64 DeserializeDataKey(SSLibV3::ColumnIterator* iters, DataKeySchema& key, IncrementalAllocator* alloc, const BYTE* blockEnd, UINT64 defaultRowId)
        {
            return defaultRowId;
        }

        //// The deserialize method that extract current RowId without advance any of the iterators.
        static SStreamRowActionType DeserializeActionType(SSLibV3::ColumnIterator* iters, const BYTE* blockEnd)
        {
            return SStreamRowActionType::Insert;
        }

        static PredFn* PredicatesLow() { return nullptr; }
        static PredFn* PredicatesHi() { return nullptr; }
        static constexpr UINT m_predicateCnt = 0;
        // Predicate lookup generation warnings :
        //  -Condition expression is null.


        typedef void (*LookupKeySerializerFn)(const CorrelatedParameters& key, AutoBuffer& buffer, std::vector<SSLibV3::LookupColumnData>& keyData);
        typedef std::array<LookupKeySerializerFn, 0> LookupKeySerializerArray;
        static const LookupKeySerializerArray& LookupKeySerializers()
        {
            static LookupKeySerializerArray s_lookupKeySerializers = {
            };

            return s_lookupKeySerializers;
        }

        static bool LowIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        // PredicateRefinedHashResidual
        static bool PredicateRefinedHashResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, int partitionIndex, int numberOfPartitions)
        {
            return true;
 
        }
    };


#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<> 
    class RowComparePolicy<Part_GetSStream_0, Part_GetSStream_0, UID_GetSStream_5> 
    {
    public:
        // compare key from left and right schema object
        static int Compare(const Part_GetSStream_0 * left, const Part_GetSStream_0 * right)
        {
            return 0;
        }
    };
#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<> 
    class SStreamV3ExtractPolicy<GetSStream_6_Data0, UID_GetSStream_6, NullSchema>
    {
    public:
        typedef NullSchema CorrelatedParameters;
        typedef bool (*PredFn)(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, CorrelatedParameters* params);

    public:
        typedef GetSStream_6_Data0 DataRowSchema;
        typedef Part_GetSStream_0 PartitionSchema;
        typedef Part_GetSStream_0 DataKeySchema;
        typedef RowComparePolicy<DataKeySchema, DataKeySchema, UID_GetSStream_6> DataKeyComparePolicy;
        typedef ResourceInputStream SystemResourceInputStream;

        static constexpr PartitioningType m_partitioning = RandomPartition;
        static constexpr bool m_residualFilterForKeyRange = false;
        static constexpr bool m_residualFilterForRefinedHash = false;
        static constexpr int  m_numberOfPartitionAfterRefinedHash = 0;
        static constexpr bool m_keyRangeSeek = false;
        static constexpr bool m_truncatedRangeKey = false;
        static constexpr bool m_readSelectedKeyRangesOnly = true;
        static constexpr bool m_generateMetadata = false;
        static constexpr UINT m_numOfBuffers = 4;
        static constexpr bool m_hasCorrelatedSchema = false;

        // FailFastSStreamRead ignores the maxUnavailability value and forces a fast failure in case of store errors
        static constexpr bool m_skipUnavailable = true; // MaxPercentInputUnavailability = 100

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>BingAdsUserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>MsAlias</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>UcmUserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>NumofWeek</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>TotalUsage</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static BYTE* DataColumnSizes()
        {
            static BYTE sizes[] = 
            {
                4,
                0,
                4,
                4,
                4,
            };

            return sizes;
        }
        static constexpr UINT m_dataColumnSizesCnt = 5;

        static BYTE* IndexColumnSizes()
        {
            static BYTE sizes[] = 
                {
                // Low key
                // Hi Key
                8, // BlockOffset
                8, // BlockLength
                4, // RowCount
                };

            return sizes;
        }
        static constexpr UINT m_indexColumnSizesCnt = 2 * 0 + 3;

        static UINT* SortKeys() { return nullptr; }
        static constexpr UINT m_sortKeysCnt = 0;

        static constexpr bool m_descending = false;


        static bool Deserialize(SSLibV3::ColumnIterator* iters, DataRowSchema & row, IncrementalAllocator* alloc, const BYTE* blockEnd, UINT32 defaultDistributionId, UINT64 defaultRowId)
        {
            STRUCTURED_DATA_ASSERT(iters[0].HasData(blockEnd));
            row.m_BingAdsUserId = iters[0].Data<int>();
            STRUCTURED_DATA_ASSERT(iters[1].HasData(blockEnd));
            if (iters[1].IsNull())
            {
                row.m_MsAlias.SetNull();
            }
            else
            {
                row.m_MsAlias.CopyFromNotNull((FString::PointerType)iters[1].DataRaw(), (int)iters[1].Length(), alloc);
            }
            STRUCTURED_DATA_ASSERT(iters[2].HasData(blockEnd));
            row.m_UcmUserId = iters[2].Data<int>();
            STRUCTURED_DATA_ASSERT(iters[3].HasData(blockEnd));
            row.m_NumofWeek = iters[3].Data<int>();
            return true;
        }

        static void SkipRow(SSLibV3::ColumnIterator* iters)
        {
            iters[0].IncrementFixedNotNullable<4>();
            if (iters[1].IsNull())
            {
                iters[1].IncrementNull();
            }
            else
            {
                iters[1].IncrementVariable();
            }
            iters[2].IncrementFixedNotNullable<4>();
            iters[3].IncrementFixedNotNullable<4>();
            //// Section of the Partition Key iterators skip.
            //// Section of the System column iterators skip.
        }

        //// The deserialize method that extract Partition Key values without advance any of the iterators.
        static UINT64 DeserializeDataKey(SSLibV3::ColumnIterator* iters, DataKeySchema& key, IncrementalAllocator* alloc, const BYTE* blockEnd, UINT64 defaultRowId)
        {
            return defaultRowId;
        }

        //// The deserialize method that extract current RowId without advance any of the iterators.
        static SStreamRowActionType DeserializeActionType(SSLibV3::ColumnIterator* iters, const BYTE* blockEnd)
        {
            return SStreamRowActionType::Insert;
        }

        static PredFn* PredicatesLow() { return nullptr; }
        static PredFn* PredicatesHi() { return nullptr; }
        static constexpr UINT m_predicateCnt = 0;
        // Predicate lookup generation warnings :
        //  -Condition expression is null.


        typedef void (*LookupKeySerializerFn)(const CorrelatedParameters& key, AutoBuffer& buffer, std::vector<SSLibV3::LookupColumnData>& keyData);
        typedef std::array<LookupKeySerializerFn, 0> LookupKeySerializerArray;
        static const LookupKeySerializerArray& LookupKeySerializers()
        {
            static LookupKeySerializerArray s_lookupKeySerializers = {
            };

            return s_lookupKeySerializers;
        }

        static bool LowIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineSeek(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool LowExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiIncludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        static bool HiExcludedPredicateRefineResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, PartitionSchema& row)
        {
            return true;
        }

        // PredicateRefinedHashResidual
        static bool PredicateRefinedHashResidual(SSLibV3::ColumnIterator* iters, IncrementalAllocator* alloc, int partitionIndex, int numberOfPartitions)
        {
            return true;
 
        }
    };


#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<> 
    class RowComparePolicy<Part_GetSStream_0, Part_GetSStream_0, UID_GetSStream_6> 
    {
    public:
        // compare key from left and right schema object
        static int Compare(const Part_GetSStream_0 * left, const Part_GetSStream_0 * right)
        {
            return 0;
        }
    };
#endif // defined(COMPILE_NATIVE)

    static const char * StringTable_Process_7 [] =
    {
        "NumofWeek",
        "BingAdsUserId",
        "MsAlias",
        "UcmUserId",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<GetSStream_6_Data0, Process_7_Data0, UID_Process_7>
    {
    public:
        static bool FilterTransformRow(GetSStream_6_Data0 & input, Process_7_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_NumofWeek = input.m_NumofWeek;
                exceptionIndex++;
                output.m_BingAdsUserId1 = input.m_BingAdsUserId;
                exceptionIndex++;
                output.m_MsAlias2 = input.m_MsAlias;
                exceptionIndex++;
                output.m_UcmUserId3 = input.m_UcmUserId;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_7[exceptionIndex]));
            }
        }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Process_9 [] =
    {
        "NumofMonth",
        "LastMonth",
        "TotalUsage",
        "NumofWeek",
        "BingAdsUserId",
        "MsAlias",
        "UcmUserId",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<HashJoin_8_Data0, SV12_Extract_Combine_out0, UID_Process_9>
    {
    public:
        static bool FilterTransformRow(HashJoin_8_Data0 & input, SV12_Extract_Combine_out0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_NumofMonth = input.m_NumofMonth;
                exceptionIndex++;
                output.m_LastMonth = input.m_LastMonth;
                exceptionIndex++;
                output.m_TotalUsage = input.m_TotalUsage;
                exceptionIndex++;
                output.m_NumofWeek = input.m_NumofWeek;
                exceptionIndex++;
                output.m_BingAdsUserId1 = input.m_BingAdsUserId;
                exceptionIndex++;
                output.m_MsAlias2 = input.m_MsAlias;
                exceptionIndex++;
                output.m_UcmUserId3 = input.m_UcmUserId;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_9[exceptionIndex]));
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


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<> 
    class KeyComparePolicy<GetSStream_5_Data0,UID_HashJoin_8_FB_0>
    {
    public:
        struct KeyStruct
        {
            int m_BingAdsUserId;
            FString m_MsAlias;
            int m_UcmUserId;

            KeyStruct(GetSStream_5_Data0 & c) :
                m_BingAdsUserId(c.m_BingAdsUserId),
                m_MsAlias(c.m_MsAlias),
                m_UcmUserId(c.m_UcmUserId)
            {
            }

            KeyStruct(const GetSStream_5_Data0 & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId(const_cast<GetSStream_5_Data0&>(c).m_BingAdsUserId),
                m_MsAlias(const_cast<GetSStream_5_Data0&>(c).m_MsAlias, alloc),
                m_UcmUserId(const_cast<GetSStream_5_Data0&>(c).m_UcmUserId)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_BingAdsUserId(c.m_BingAdsUserId),
                m_MsAlias(c.m_MsAlias),
                m_UcmUserId(c.m_UcmUserId)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId(const_cast<KeyStruct&>(c).m_BingAdsUserId),
                m_MsAlias(const_cast<KeyStruct&>(c).m_MsAlias, alloc),
                m_UcmUserId(const_cast<KeyStruct&>(c).m_UcmUserId)
            {
            }

            KeyStruct() :
                m_BingAdsUserId(0),
                m_MsAlias(),
                m_UcmUserId(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(GetSStream_5_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_BingAdsUserId, key.m_BingAdsUserId)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_MsAlias, key.m_MsAlias)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_UcmUserId, key.m_UcmUserId)) != 0)
                return r;
            return r;
        }

        static int Compare(GetSStream_5_Data0 * n1, GetSStream_5_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId, (*n2).m_BingAdsUserId)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias, (*n2).m_MsAlias)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId, (*n2).m_UcmUserId)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(GetSStream_5_Data0 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_BingAdsUserId);
            }

            --depth;
            if (depth < 1 && (*p).m_MsAlias.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_MsAlias.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_MsAlias.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_MsAlias.buffer()[depth]));
            }

            depth -= (int) ((*p).m_MsAlias.size() + 1);

            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_UcmUserId);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(GetSStream_5_Data0 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            depth -= (int) ((*p).m_MsAlias.size() + 1);
            if (depth < 0)
                return false;
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };




    template<> 
    class KeyComparePolicy<Process_7_Data0,UID_HashJoin_8_FB_1>
    {
    public:
        struct KeyStruct
        {
            int m_BingAdsUserId1;
            FString m_MsAlias2;
            int m_UcmUserId3;

            KeyStruct(Process_7_Data0 & c) :
                m_BingAdsUserId1(c.m_BingAdsUserId1),
                m_MsAlias2(c.m_MsAlias2),
                m_UcmUserId3(c.m_UcmUserId3)
            {
            }

            KeyStruct(const Process_7_Data0 & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId1(const_cast<Process_7_Data0&>(c).m_BingAdsUserId1),
                m_MsAlias2(const_cast<Process_7_Data0&>(c).m_MsAlias2, alloc),
                m_UcmUserId3(const_cast<Process_7_Data0&>(c).m_UcmUserId3)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_BingAdsUserId1(c.m_BingAdsUserId1),
                m_MsAlias2(c.m_MsAlias2),
                m_UcmUserId3(c.m_UcmUserId3)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId1(const_cast<KeyStruct&>(c).m_BingAdsUserId1),
                m_MsAlias2(const_cast<KeyStruct&>(c).m_MsAlias2, alloc),
                m_UcmUserId3(const_cast<KeyStruct&>(c).m_UcmUserId3)
            {
            }

            KeyStruct() :
                m_BingAdsUserId1(0),
                m_MsAlias2(),
                m_UcmUserId3(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"BingAdsUserId1:int,MsAlias2:string,UcmUserId3:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Process_7_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_BingAdsUserId1, key.m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_MsAlias2, key.m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_UcmUserId3, key.m_UcmUserId3)) != 0)
                return r;
            return r;
        }

        static int Compare(Process_7_Data0 * n1, Process_7_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId1, (*n2).m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias2, (*n2).m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId3, (*n2).m_UcmUserId3)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Process_7_Data0 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_BingAdsUserId1);
            }

            --depth;
            if (depth < 1 && (*p).m_MsAlias2.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_MsAlias2.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_MsAlias2.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_MsAlias2.buffer()[depth]));
            }

            depth -= (int) ((*p).m_MsAlias2.size() + 1);

            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_UcmUserId3);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Process_7_Data0 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            depth -= (int) ((*p).m_MsAlias2.size() + 1);
            if (depth < 0)
                return false;
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };




    template<> 
    class KeyComparePolicy<GetSStream_5_Data0,UID_HashJoin_8_0>
    {
    public:
        struct KeyStruct
        {
            int m_BingAdsUserId;
            FString m_MsAlias;
            int m_UcmUserId;

            KeyStruct(GetSStream_5_Data0 & c) :
                m_BingAdsUserId(c.m_BingAdsUserId),
                m_MsAlias(c.m_MsAlias),
                m_UcmUserId(c.m_UcmUserId)
            {
            }

            KeyStruct(const GetSStream_5_Data0 & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId(const_cast<GetSStream_5_Data0&>(c).m_BingAdsUserId),
                m_MsAlias(const_cast<GetSStream_5_Data0&>(c).m_MsAlias, alloc),
                m_UcmUserId(const_cast<GetSStream_5_Data0&>(c).m_UcmUserId)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_BingAdsUserId(c.m_BingAdsUserId),
                m_MsAlias(c.m_MsAlias),
                m_UcmUserId(c.m_UcmUserId)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId(const_cast<KeyStruct&>(c).m_BingAdsUserId),
                m_MsAlias(const_cast<KeyStruct&>(c).m_MsAlias, alloc),
                m_UcmUserId(const_cast<KeyStruct&>(c).m_UcmUserId)
            {
            }

            KeyStruct() :
                m_BingAdsUserId(0),
                m_MsAlias(),
                m_UcmUserId(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(GetSStream_5_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_BingAdsUserId, key.m_BingAdsUserId)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_MsAlias, key.m_MsAlias)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_UcmUserId, key.m_UcmUserId)) != 0)
                return r;
            return r;
        }

        static int Compare(GetSStream_5_Data0 * n1, GetSStream_5_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId, (*n2).m_BingAdsUserId)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias, (*n2).m_MsAlias)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId, (*n2).m_UcmUserId)) != 0)
                return r;
            return r;
        }

    };




    template<> 
    class KeyComparePolicy<Process_7_Data0,UID_HashJoin_8_1>
    {
    public:
        struct KeyStruct
        {
            int m_BingAdsUserId1;
            FString m_MsAlias2;
            int m_UcmUserId3;

            KeyStruct(Process_7_Data0 & c) :
                m_BingAdsUserId1(c.m_BingAdsUserId1),
                m_MsAlias2(c.m_MsAlias2),
                m_UcmUserId3(c.m_UcmUserId3)
            {
            }

            KeyStruct(const Process_7_Data0 & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId1(const_cast<Process_7_Data0&>(c).m_BingAdsUserId1),
                m_MsAlias2(const_cast<Process_7_Data0&>(c).m_MsAlias2, alloc),
                m_UcmUserId3(const_cast<Process_7_Data0&>(c).m_UcmUserId3)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_BingAdsUserId1(c.m_BingAdsUserId1),
                m_MsAlias2(c.m_MsAlias2),
                m_UcmUserId3(c.m_UcmUserId3)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId1(const_cast<KeyStruct&>(c).m_BingAdsUserId1),
                m_MsAlias2(const_cast<KeyStruct&>(c).m_MsAlias2, alloc),
                m_UcmUserId3(const_cast<KeyStruct&>(c).m_UcmUserId3)
            {
            }

            KeyStruct() :
                m_BingAdsUserId1(0),
                m_MsAlias2(),
                m_UcmUserId3(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"BingAdsUserId1:int,MsAlias2:string,UcmUserId3:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Process_7_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_BingAdsUserId1, key.m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_MsAlias2, key.m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_UcmUserId3, key.m_UcmUserId3)) != 0)
                return r;
            return r;
        }

        static int Compare(Process_7_Data0 * n1, Process_7_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId1, (*n2).m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias2, (*n2).m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId3, (*n2).m_UcmUserId3)) != 0)
                return r;
            return r;
        }

    };



#if defined(COMPILE_NATIVE)
    template<>
    class RowHashPolicy<GetSStream_5_Data0,UID_HashJoin_8>
    {
    public:
        static __int64 Hash(GetSStream_5_Data0* row)
        {
            ScopeRowHasher hasher;
            hasher.HashColumnValue<int> ((*row).m_BingAdsUserId);
            hasher.HashColumnValue<FString> ((*row).m_MsAlias);
            hasher.HashColumnValue<int> ((*row).m_UcmUserId);
            return hasher.ComputeHashCode();
        }

        INLINE static int Bucket(GetSStream_5_Data0* row, int bucketCount)
        {
            return ScopeRowHasher::ComputeBucket(Hash(row), bucketCount);
        }
    };

#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)




#if defined(COMPILE_NATIVE)
    template<> 
    class CombinerPolicy<UID_HashJoin_8> 
    {
    public:
        typedef KeyComparePolicy<GetSStream_5_Data0,UID_HashJoin_8_0> LeftKeyPolicy;
        typedef KeyComparePolicy<Process_7_Data0,UID_HashJoin_8_1> RightKeyPolicy;

        static constexpr unsigned MaxPerKeyCrossSizeLimit = 0;

        static LONGLONG JoinerMemQuota()
        {
            return 262144000ULL;
        }

        // compare key from left and right schema object
        static int Compare(const GetSStream_5_Data0 * left, const Process_7_Data0 * right)
        {
            int r = 0;
            GetSStream_5_Data0 * n1 = const_cast<GetSStream_5_Data0 *>(left);
            Process_7_Data0 * n2 = const_cast<Process_7_Data0 *>(right);

            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId, (*n2).m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias, (*n2).m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId, (*n2).m_UcmUserId3)) != 0)
                return r;
            
            // Everything matches
            return 0;
        }

        static void CopyRow(GetSStream_5_Data0 * left, Process_7_Data0 * right, HashJoin_8_Data0 * out)
        {
                (*out).m_BingAdsUserId = (*left).m_BingAdsUserId;
                (*out).m_MsAlias = (*left).m_MsAlias;
                (*out).m_UcmUserId = (*left).m_UcmUserId;
                (*out).m_NumofMonth = (*left).m_NumofMonth;
                (*out).m_LastMonth = (*left).m_LastMonth;
                (*out).m_TotalUsage = (*left).m_TotalUsage;
                (*out).m_NumofWeek = (*right).m_NumofWeek;
        }

        static void CopyLeftRow(GetSStream_5_Data0 * left, HashJoin_8_Data0 * out)
        {
            (*out).m_BingAdsUserId = (*left).m_BingAdsUserId;
            (*out).m_MsAlias = (*left).m_MsAlias;
            (*out).m_UcmUserId = (*left).m_UcmUserId;
            (*out).m_NumofMonth = (*left).m_NumofMonth;
            (*out).m_LastMonth = (*left).m_LastMonth;
            (*out).m_TotalUsage = (*left).m_TotalUsage;
        }

        static void NullifyLeftSide(HashJoin_8_Data0 * out)
        {
            (*out).m_MsAlias.SetNull();
            (*out).m_LastMonth.SetNull();
        }

        static void CopyRightRow(Process_7_Data0 * right, HashJoin_8_Data0 * out)
        {
            (*out).m_NumofWeek = (*right).m_NumofWeek;
        }

        static void NullifyRightSide(HashJoin_8_Data0 * out)
        {
        }
    };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
    template<>
    class HashCombinerWithFallbackPolicy<GetSStream_5_Data0, Process_7_Data0, HashJoin_8_Data0, UID_HashJoin_8>
    {
    public:
        static constexpr int ProbeSorterUID = UID_HashJoin_8_FB_0;
        static constexpr int BuildSorterUID = UID_HashJoin_8_FB_1;
        typedef StdSort<GetSStream_5_Data0> ProbeSorterAlgorithm;
        typedef StdSort<Process_7_Data0> BuildSorterAlgorithm;
    };

    template <>
    class HashCombinerPolicyV2<GetSStream_5_Data0, Process_7_Data0, HashJoin_8_Data0, UID_HashJoin_8>
    {
    public:
        typedef HashCombinerPolicyV2<GetSStream_5_Data0, Process_7_Data0, HashJoin_8_Data0, UID_HashJoin_8> P;

        typedef HashCmbnKey_HashJoin_8 KeySchema;
        typedef HashCmbnVal_HashJoin_8 ValueSchema;

        // >> define hash & equal functions
        struct Hash
        {
            const INT64 m_seed;

            Hash() : m_seed((INT64)0) {}
            Hash(INT64 seed) : m_seed(seed) {}

            INT64 operator () (const HashCmbnKey_HashJoin_8& schema) const
            {
                INT64 result = m_seed;
                    result += ScopeHash(schema.m_BingAdsUserId_BingAdsUserId1);
                    result += ScopeHash(schema.m_MsAlias_MsAlias2);
                    result += ScopeHash(schema.m_UcmUserId_UcmUserId3);
                
                return result;
            }
        };

        struct BuildHash
        {
            const INT64 m_seed;

            BuildHash() : m_seed((INT64)0) {}
            BuildHash(INT64 seed) : m_seed(seed) {}

            INT64 operator () (const Process_7_Data0& schema) const
            {
                INT64 result = m_seed;
                    result += ScopeHash(schema.m_BingAdsUserId1);
                    result += ScopeHash(schema.m_MsAlias2);
                    result += ScopeHash(schema.m_UcmUserId3);
                
                return result;
            }
        };

        struct ProbeHash
        {
            const INT64 m_seed;

            ProbeHash() : m_seed((INT64)0) {}
            ProbeHash(INT64 seed) : m_seed(seed) {}

            INT64 operator () (const GetSStream_5_Data0& schema) const
            {
                INT64 result = m_seed;
                    result += ScopeHash(schema.m_BingAdsUserId);
                    result += ScopeHash(schema.m_MsAlias);
                    result += ScopeHash(schema.m_UcmUserId);
                
                return result;
            }
        };

        struct EqualTo
        {
            bool operator () (const HashCmbnKey_HashJoin_8& left, const HashCmbnKey_HashJoin_8& right) const
            {
                if (!ScopeTypeCompare_EqualEqual(left.m_BingAdsUserId_BingAdsUserId1, right.m_BingAdsUserId_BingAdsUserId1)) return false;
                if (!ScopeTypeCompare_EqualEqual(left.m_MsAlias_MsAlias2, right.m_MsAlias_MsAlias2)) return false;
                if (!ScopeTypeCompare_EqualEqual(left.m_UcmUserId_UcmUserId3, right.m_UcmUserId_UcmUserId3)) return false;
                return true;
            }
        };
        struct ProbeEqualTo
        {
            bool operator () (const GetSStream_5_Data0& left, const HashCmbnKey_HashJoin_8& right) const
            {
                if (!ScopeTypeCompare_EqualEqual(left.m_BingAdsUserId, right.m_BingAdsUserId_BingAdsUserId1)) return false;
                if (!ScopeTypeCompare_EqualEqual(left.m_MsAlias, right.m_MsAlias_MsAlias2)) return false;
                if (!ScopeTypeCompare_EqualEqual(left.m_UcmUserId, right.m_UcmUserId_UcmUserId3)) return false;
                return true;
            }
        };
        static INT64* Seed()
        {
            static INT64 seed[] { 31607, 40529 };
            return seed;
        }

        static BuildHash* BuildHashes()
        {
            static BuildHash hashes[] { BuildHash(Seed()[0]), BuildHash(Seed()[1]) };
            return hashes;
        }

        static ProbeHash* ProbeHashes()
        {
            static ProbeHash hashes[] { ProbeHash(Seed()[0]), ProbeHash(Seed()[1]) };
            return hashes;
        }

        static constexpr size_t s_seedCnt{ 2 };

        // << define hash & equal functions

        // >> define spilling
        struct Spilling
        {
            static constexpr size_t s_bufferSize{ 4 * 1024 * 1024 }; //4MB
            static constexpr size_t s_bufferCnt{ 2 };
            static constexpr bool s_disable{ false };
            static constexpr bool s_raiseUserError{ false };
        };
        // << define spilling

        // >> define constants
        static constexpr size_t s_memoryQuota{ 2206203280ULL }; // Cosmos default is 2GB

        // the maximum number of buckets in the hashtable is defined as 
        // s_directorySize * 2^s_segmentSizeExponent => 67 108 864
        // s_directorySize has to be a power of two
        static constexpr size_t s_directorySize{ 4096 };
        static constexpr size_t s_segmentSizeExponent{ 14 }; // 16384 bucket per segment

         // number of hashtables used in the join, the data is spilled one hashtable at a time
        static constexpr size_t s_hashtableCntExponent{ 2 }; // 4 hashtables

         // initial number of buckets per hashtable
         // s_initialSize has to be a power of two
        static constexpr size_t s_initialSize { 128 * (1 << s_segmentSizeExponent) };

        // the length of the segment of the value list is defined as
        // 2^s_valueListSegmentSizeExponent => 1
        static constexpr size_t s_valueListSegmentSizeExponent{ 0 };

        static constexpr size_t s_maxPerKeyCrossSizeLimit{ 0 };
        // << define constants

        typedef STLIncrementalAllocator<char> CharAllocator;
        typedef GranularList<ValueSchema*, s_valueListSegmentSizeExponent, CharAllocator> UnderlyingValue;
        typedef UnderlyingValue Value;
        typedef Value::Iterator ValueIterator;

        template <typename Item, typename CharAllocator>
        struct HashtablePolicy : public SlimHashtableLayoutPolicy<Item, CharAllocator>::Type
        {
            struct BucketArrayTraits
            {
                static constexpr size_t s_directorySize{ P::s_directorySize };
                static constexpr size_t s_segmentSizeExponent{ P::s_segmentSizeExponent };
            };
        };

        typedef SlimHashMap<KeySchema, Value, HashtablePolicy, Hash, EqualTo> Hashtable;

        static constexpr HashCombinerValuesPerKeyCountV2 s_valuesPerKeyCount = HashCombinerValuesPerKeyCountV2::MANY;

        static void UpdateValueList(CharAllocator& alloc, Value& valueList, ValueSchema* value)
        {
            valueList.EmplaceFront(alloc, value);
        }

        static ValueIterator ValueListBegin(Value& valueList)
        {
            return valueList.Begin();
        }
        
        static ValueIterator ValueListEnd(Value& valueList)
        {
            return valueList.End();
        }
        
        static size_t ValueListSize(const Value& valueList)
        {
            return valueList.Size();
        }

        static size_t IncrementValueListStats(Value& valueList)
        {
            return 0;
        }

    
        // Shallow copy probe and build schema fields to the output
        static void CopyBoth(const GetSStream_5_Data0 & probe, const ValueSchema * build, HashJoin_8_Data0 & output)
        {
            // copy probe
            output.m_BingAdsUserId = probe.m_BingAdsUserId;
            output.m_MsAlias = probe.m_MsAlias;
            output.m_UcmUserId = probe.m_UcmUserId;
            output.m_NumofMonth = probe.m_NumofMonth;
            output.m_LastMonth = probe.m_LastMonth;
            output.m_TotalUsage = probe.m_TotalUsage;

            // copy build
            output.m_NumofWeek = (*build).m_NumofWeek;
        }

        // Shallow copy probe schema fields to the output and nullify all the rest
        static void CopyProbeAndNullifyBuild(const GetSStream_5_Data0 & probe, HashJoin_8_Data0 & output)
        {
            // copy probe
            output.m_BingAdsUserId = probe.m_BingAdsUserId;
            output.m_MsAlias = probe.m_MsAlias;
            output.m_UcmUserId = probe.m_UcmUserId;
            output.m_NumofMonth = probe.m_NumofMonth;
            output.m_LastMonth = probe.m_LastMonth;
            output.m_TotalUsage = probe.m_TotalUsage;

            // nullify build
        }

         static void DeepCopyBuildRowToKeyValue(const Process_7_Data0 & row, KeySchema & key, ValueSchema * value, IncrementalAllocator* alloc)
         {
            // copy key
           key.m_BingAdsUserId_BingAdsUserId1 = row.m_BingAdsUserId1;
            FString tmp_MsAlias2(row.m_MsAlias2, alloc);
           key.m_MsAlias_MsAlias2 = tmp_MsAlias2;
           key.m_UcmUserId_UcmUserId3 = row.m_UcmUserId3;
            // copy value
            (*value).m_NumofWeek = row.m_NumofWeek;
         }

         static void CopyKeyValueToBuildRow(const KeySchema & key, const ValueSchema * value, Process_7_Data0 & row)
         {
            // copy key
           row.m_BingAdsUserId1 = key.m_BingAdsUserId_BingAdsUserId1;
           row.m_MsAlias2 = key.m_MsAlias_MsAlias2;
           row.m_UcmUserId3 = key.m_UcmUserId_UcmUserId3;
            // copy value
            row.m_NumofWeek = (*value).m_NumofWeek;
         }

        static void InsertOrUpdate(Hashtable& ht, const Process_7_Data0 & row, INT64 hash, IncrementalAllocator& alloc, CharAllocator& calloc)
        {
            KeySchema key;
            ValueSchema* value = new (alloc.Allocate(sizeof(ValueSchema))) ValueSchema();
            DeepCopyBuildRowToKeyValue(row, key, value, &alloc);

            Value vlist;
            auto it = ht.InsertWithPrecomputedHash(hash, { key, vlist });
            UpdateValueList(calloc, it.first->second, value);
        }
    };

#endif // defined(COMPILE_NATIVE)





#if defined(COMPILE_NATIVE)
    using SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5 = SStreamExtractorV4<GetSStream_5_Data0, SStreamV3ExtractPolicy<GetSStream_5_Data0, UID_GetSStream_5, NullSchema>, UID_GetSStream_5, NullSchema, false>;
    SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5 * CreateExtractor_SV12_Extr_Cmbn_GetSStream_5(unique_ptr<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5> * extractor_ptr)
    {
        extractor_ptr->reset(new SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5(5, "", UID_GetSStream_5));
        return extractor_ptr->get();
    }
#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    using SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6 = SStreamExtractorV4<GetSStream_6_Data0, SStreamV3ExtractPolicy<GetSStream_6_Data0, UID_GetSStream_6, NullSchema>, UID_GetSStream_6, NullSchema, false>;
    SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6 * CreateExtractor_SV12_Extr_Cmbn_GetSStream_6(unique_ptr<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6> * extractor_ptr)
    {
        extractor_ptr->reset(new SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6(6, "", UID_GetSStream_6));
        return extractor_ptr->get();
    }
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_NATIVE)
struct FilterTransformerType_Process_7 : FilterTransformer<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6, GetSStream_6_Data0, Process_7_Data0, UID_Process_7> { using FilterTransformer<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6, GetSStream_6_Data0, Process_7_Data0, UID_Process_7>::FilterTransformer; };
struct CombinerType_HashJoin_8 : HashCombinerWithFallback<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5, GetSStream_5_Data0, FilterTransformerType_Process_7, Process_7_Data0, HashJoin_8_Data0, HashInnerJoinerV2, InnerJoiner, UID_HashJoin_8> { using HashCombinerWithFallback<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5, GetSStream_5_Data0, FilterTransformerType_Process_7, Process_7_Data0, HashJoin_8_Data0, HashInnerJoinerV2, InnerJoiner, UID_HashJoin_8>::HashCombinerWithFallback; };
struct FilterTransformerType_Process_9 : FilterTransformer<CombinerType_HashJoin_8, HashJoin_8_Data0, SV12_Extract_Combine_out0, UID_Process_9> { using FilterTransformer<CombinerType_HashJoin_8, HashJoin_8_Data0, SV12_Extract_Combine_out0, UID_Process_9>::FilterTransformer; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV12_Extract_Combine_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        unique_ptr<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5> extractor_0_ptr;
        SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5 * extractor_0 = CreateExtractor_SV12_Extr_Cmbn_GetSStream_5(&extractor_0_ptr);
        ULONG extractor_0_count = 1;

        unique_ptr<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6> extractor_1_ptr;
        SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6 * extractor_1 = CreateExtractor_SV12_Extr_Cmbn_GetSStream_6(&extractor_1_ptr);
        ULONG extractor_1_count = 1;


        // FilterTransformerType_Process_7: FilterTransformer<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_6, GetSStream_6_Data0, Process_7_Data0, UID_Process_7>
        unique_ptr<FilterTransformerType_Process_7> filterTransformer_Process_7_ptr (new FilterTransformerType_Process_7(extractor_1, UID_Process_7));
        FilterTransformerType_Process_7 * filterTransformer_Process_7 = filterTransformer_Process_7_ptr.get();
        ULONG filterTransformer_Process_7_count = 1;

        // CombinerType_HashJoin_8: HashCombinerWithFallback<SStreamV3ExtractorType_SV12_Extr_Cmbn_GetSStream_5, GetSStream_5_Data0, FilterTransformerType_Process_7, Process_7_Data0, HashJoin_8_Data0, HashInnerJoinerV2, InnerJoiner, UID_HashJoin_8>
        unique_ptr<CombinerType_HashJoin_8> combiner_HashJoin_8_ptr;
        combiner_HashJoin_8_ptr.reset(new CombinerType_HashJoin_8(extractor_0, filterTransformer_Process_7, UID_HashJoin_8, 0));

        CombinerType_HashJoin_8 * combiner_HashJoin_8 = combiner_HashJoin_8_ptr.get();
        ULONG combiner_HashJoin_8_count = 1;

        // FilterTransformerType_Process_9: FilterTransformer<CombinerType_HashJoin_8, HashJoin_8_Data0, SV12_Extract_Combine_out0, UID_Process_9>
        unique_ptr<FilterTransformerType_Process_9> filterTransformer_Process_9_ptr (new FilterTransformerType_Process_9(combiner_HashJoin_8, UID_Process_9));
        FilterTransformerType_Process_9 * filterTransformer_Process_9 = filterTransformer_Process_9_ptr.get();
        ULONG filterTransformer_Process_9_count = 1;

        using OutputterType1_SV12_Extr_Cmbn = Outputter<FilterTransformerType_Process_9, SV12_Extract_Combine_out0, BinaryOutputPolicy<SV12_Extract_Combine_out0>, BinaryOutputStream, false>;
        unique_ptr<OutputterType1_SV12_Extr_Cmbn> outputter_SV12_Extract_Combine_out0_ptr(new OutputterType1_SV12_Extr_Cmbn(filterTransformer_Process_9, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, UID_SV12_Extract_Combine_out0, false));
        OutputterType1_SV12_Extr_Cmbn * outputter_SV12_Extract_Combine_out0 = outputter_SV12_Extract_Combine_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV12_Extract_Combine_out0) };

        try
        {
            // Init operator chain
            outputter_SV12_Extract_Combine_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            SV12_Extract_Combine_out0 row;
            outputter_SV12_Extract_Combine_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV12_Extract_Combine_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV12_Extract_Combine_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV12_Extract_Combine
#pragma region SV13_Combine_Split
#if defined(COMPILE_SV13_COMBINE_SPLIT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_NATIVE)
    template<>
    class SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>
    {
    public:
        SStreamV3OutputPolicy(UINT)
        {
        }

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>BingAdsUserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>MsAlias</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>UcmUserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>FreqSegment</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>NumofMonth</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>LastMonth</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>NumofWeek</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>TotalUsage</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static std::array<const char *, 8> m_columnNames;
        static std::array<const char *, 8> m_columnTypes;
        static std::array<BYTE, 8> m_dataColumnSizes;
        static std::array<BYTE, 3> m_indexColumnSizes;
        static UINT* m_dataPageSortKeys;
        static const char ** m_dataPageSortOrders;
        static const char *  m_dataPageSortUniq;
        static constexpr UINT m_dataPageSortKeysCnt = 0;

        static const char m_partitionType[];
        static constexpr UINT m_partitionColumnCount = 0;

        static UINT *     m_partitionKeys;
        static const char **  m_partitionOrders;
        static constexpr int m_blockSize = 4194304;
        static constexpr int m_uncompressedBlockSize = 11733735;
        static constexpr bool m_enableAutoPrimaryBloomFilter = true;
        static constexpr int m_bloomFilterSizeWriteRatio = -1;
        static constexpr int m_bloomFilterVersion = -1;
        static int GetPartitionIndex(const Process_12_Data0& row)
        {
            // Global sstream outputter does not care partition index.
            UNREFERENCED_PARAMETER(row);
            return 0;
            
        }        
        static void SerializeRow(HANDLE rowHandle, AutoBuffer* buffer, int* columnOffsets, SIZE_T arraySize)
        {
            UNREFERENCED_PARAMETER(arraySize);
            
            Process_12_Data0& row = *(Process_12_Data0*)rowHandle;
            SStreamDataOutputStream output(buffer);

            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            if (row.m_MsAlias.IsNull())
            {
                ___masking___[0] |= 2;
            }
            if (row.m_FreqSegment.IsNull())
            {
                ___masking___[0] |= 8;
            }
            if (row.m_LastMonth.IsNull())
            {
                ___masking___[0] |= 32;
            }
            auto rowStart = output.GetPosition();

            // write a null mask regardless whether there are nullable columns,
            // if there aren't any nullable column, simply write the array's 
            // initial values, which are zeros.
            output.Write(___masking___, sizeof(___masking___));


            columnOffsets[0] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_BingAdsUserId);

            columnOffsets[1] = (int)(output.GetPosition() - rowStart);
            if (!row.m_MsAlias.IsNull())
            {
                output.Write(row.m_MsAlias);
            }

            columnOffsets[2] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_UcmUserId);

            columnOffsets[3] = (int)(output.GetPosition() - rowStart);
            if (!row.m_FreqSegment.IsNull())
            {
                output.Write(row.m_FreqSegment);
            }

            columnOffsets[4] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_NumofMonth);

            columnOffsets[5] = (int)(output.GetPosition() - rowStart);
            if (!row.m_LastMonth.IsNull())
            {
                output.Write(row.m_LastMonth);
            }

            columnOffsets[6] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_NumofWeek);

            columnOffsets[7] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_TotalUsage);

            columnOffsets[8] = (int)(output.GetPosition() - rowStart);
        }

        static constexpr SStreamVersion m_streamVersion = ScopeEngine::SStreamVersion::SSTREAM_VERSION_V3;
    };

#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<>
    class SStreamPartitionWriter<Process_12_Data0, UID_SStreamOutput_13>
    {
    private:
        SStreamOutputStream<Process_12_Data0, SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>, void, -1> sstreamOutputStream_0;
        BlockDevice*    m_metadataDevice;
        int             m_bufCount;
        int             m_sequenceNumber;
        int             m_distributionId;
        bool            m_preferSSD;
    public:
        static constexpr int VALUE_NOT_INITIALIZED = -3;

        
        SStreamPartitionWriter(OutputFileInfo outputs, const string& outputMetadataFileName, bool preferSSD, bool enableBloomFilter)
            : SStreamPartitionWriter(&outputs, 1, outputMetadataFileName, preferSSD, enableBloomFilter)
        {
        }

        
        SStreamPartitionWriter(OutputFileInfo* outputs, int fileCnt, const string& outputMetadataFileName, bool preferSSD, bool enableBloomFilter)
            : m_bufCount(0)
            , m_sequenceNumber(VALUE_NOT_INITIALIZED)
            , m_preferSSD(preferSSD)
            , m_distributionId(0)
            
            , sstreamOutputStream_0(outputs[0].outputFileName, 0, outputs[0].bufferSize, outputs[0].bufferCount, preferSSD, enableBloomFilter)
            , m_metadataDevice(ScopeEngine::IOManager::GetGlobal()->GetDevice(outputMetadataFileName))
        {
            STRUCTURED_DATA_ASSERT(fileCnt == 1);

            for(int idx = 0; idx < fileCnt; ++idx)
            {
                m_bufCount = std::max(m_bufCount, outputs[idx].bufferCount);
            }
        }

        void Init()
        {
            constexpr int64_t expectedNumberOfRowsPerPartition_0 = 4995000001ll;
            sstreamOutputStream_0.Init(expectedNumberOfRowsPerPartition_0);
        }

        void SetSequenceNumber(int sequenceNumber)
        {
            m_sequenceNumber = sequenceNumber;
            m_distributionId = 0;
        }

        bool NeedMetadata()
        {
            return -1 != -1;
        }

        void SetPartitionInfo(PartitionMetadata* payload)
        {
            sstreamOutputStream_0.SetPartitionInfo(payload);
            // If the m_distributionId hasn't been set, then we can initialize it
            // If the first OutputStream has a valid PartitionID, then use it. 
            // do we have a value from our payload?
            // all column groups must have the same distribution id, so just use the first group
            if(sstreamOutputStream_0.ValidPartition())
            {
                m_distributionId = sstreamOutputStream_0.GetPartitionIndex();
            }
        }

        bool ValidPartition()
        {
            return m_distributionId != PartitionMetadata::PARTITION_NOT_EXIST;
        }

        void AppendRow(Process_12_Data0 & output)
        {
            sstreamOutputStream_0.AppendRow(output);
        }

        void Close()
        {
            sstreamOutputStream_0.Close();


            unique_ptr<SStreamMetadata> metadata(SStreamMetadata::CreateMetadataByVersion(ScopeEngine::SStreamVersion::SSTREAM_VERSION_V3, MemoryManager::GetGlobal()));
            std::string streamSchema = std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>BingAdsUserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>MsAlias</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>UcmUserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>FreqSegment</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>NumofMonth</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>LastMonth</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>NumofWeek</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>TotalUsage</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" };

            shared_ptr<vector<ScopeEngine::SSLibV3::ColumnGroupInfo>> colGroupInfos = make_shared<vector<ScopeEngine::SSLibV3::ColumnGroupInfo>>(1);
            shared_ptr<vector<ScopeEngine::SSLibV3::DataunitTableRow>> dataUnitTableRows = make_shared<vector<ScopeEngine::SSLibV3::DataunitTableRow>>(1);
            shared_ptr<ScopeEngine::SSLibV3::SStreamStatistics> statistics;
            statistics = sstreamOutputStream_0.GetStatistics();
            std::string dataSchema_0 = SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::DataSchemaString();

            ScopeEngine::SSLibV3::ColumnGroupInfo& colGroupInfo_0 = (*colGroupInfos)[0];
            colGroupInfo_0.m_columnGroupIndex = 0;
            colGroupInfo_0.m_columnGroupSchema = dataSchema_0;

            ScopeEngine::SSLibV3::DataunitTableRow& dataunitInfo_0 = (*dataUnitTableRows)[0];
            dataunitInfo_0.m_PartitionIndex = m_distributionId;
            dataunitInfo_0.m_ColumnGroupIndex = 0;
            dataunitInfo_0.m_Offset = 0;
            dataunitInfo_0.m_Length = sstreamOutputStream_0.Length();
            dataunitInfo_0.m_DataLength = sstreamOutputStream_0.DataLength();
            dataunitInfo_0.m_RowCount = sstreamOutputStream_0.RowCount();
            dataunitInfo_0.m_DeltaIndex = 0;

            shared_ptr<vector<ScopeEngine::SSLibV3::PartitionInfoTableRow>> partInfoRows = make_shared<vector<ScopeEngine::SSLibV3::PartitionInfoTableRow>>(1);
            ScopeEngine::SSLibV3::PartitionInfoTableRow& partInfo = (*partInfoRows)[0];
            // all column groups have the same partition information
            partInfo.m_PartitionKeyRange = sstreamOutputStream_0.GetPartitionKeyRange();
            partInfo.m_BeginPartitionIndex = m_distributionId;
            partInfo.m_AffinityId = GuidToString(sstreamOutputStream_0.GetAffinityGuid());

            metadata->Initialize(streamSchema,
                colGroupInfos,
                dataUnitTableRows,
                partInfoRows,
                statistics);

            metadata->PreferSSD(m_preferSSD);
            metadata->Write(m_metadataDevice);
        }

        LONGLONG GetTotalIoWaitTime() const
        {
            LONGLONG time = 0;
            time += sstreamOutputStream_0.GetTotalIoWaitTime();
            return time;
        }

        void WriteRuntimeStats(TreeNode & root) const
        {
            sstreamOutputStream_0.WriteRuntimeStats(root);
        }

        // get operator resource requirements
        ScopeEngine::OperatorRequirements GetOperatorRequirements(SIZE_T bufferCount)
        {
            return ScopeEngine::OperatorRequirements()
                .AddMemoryForOutputSStreams(1, Configuration::GetGlobal().GetMaxInMemoryRowSize(), m_bufCount);
        }

        // the following methods are for SplitOutputter
        void WriteMetadata(PartitionMetadata* metadata)
        {
            SetPartitionInfo(metadata);
        }

        void Finish()
        {
            // do nothing
        }

        void Flush(bool forcePersistent = false)
        {
            // do nothing
            (forcePersistent);
        }
    };

#endif

    static const char * StringTable_Process_11 [] =
    {
        "BingAdsUserId",
        "MsAlias",
        "UcmUserId",
        "NumofMonth ?? -1",
        "LastMonth ?? \"Non\"",
        "NumofWeek ?? -1",
        "TotalUsage ?? -1",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<HashJoin_10_Data0, Process_11_Data0, UID_Process_11>
    {
    public:
        static bool FilterTransformRow(HashJoin_10_Data0 & input, Process_11_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_BingAdsUserId = input.m_BingAdsUserId;
                exceptionIndex++;
                output.m_MsAlias = input.m_MsAlias;
                exceptionIndex++;
                output.m_UcmUserId = input.m_UcmUserId;
                exceptionIndex++;
                output.m_NumofMonth = ScopeCoalesce(input.m_NumofMonth, [&]() { return -1; });
                exceptionIndex++;
                output.m_LastMonth = ScopeCoalesce(input.m_LastMonth, [&]() { return staticconstant_0; });
                exceptionIndex++;
                output.m_NumofWeek = ScopeCoalesce(input.m_NumofWeek, [&]() { return -1; });
                exceptionIndex++;
                output.m_TotalUsage = ScopeCoalesce(input.m_TotalUsage, [&]() { return -1; });
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_11[exceptionIndex]));
            }
        }
            static FString staticconstant_0;

        #pragma warning(push)
        #pragma warning(disable: 4100) // 'alloc': unreferenced formal parameter
        static void InitializeStatics(IncrementalAllocator * alloc)
        {
        #pragma warning(pop)

            staticconstant_0 = FString("Non", 3);
        }

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements().AddMemoryInRows(1, 1);
        }
    };




#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<> 
    class KeyComparePolicy<SV3_Extract_out0,UID_HashJoin_10_FB_0>
    {
    public:
        struct KeyStruct
        {
            int m_BingAdsUserId;
            FString m_MsAlias;
            int m_UcmUserId;

            KeyStruct(SV3_Extract_out0 & c) :
                m_BingAdsUserId(c.m_BingAdsUserId),
                m_MsAlias(c.m_MsAlias),
                m_UcmUserId(c.m_UcmUserId)
            {
            }

            KeyStruct(const SV3_Extract_out0 & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId(const_cast<SV3_Extract_out0&>(c).m_BingAdsUserId),
                m_MsAlias(const_cast<SV3_Extract_out0&>(c).m_MsAlias, alloc),
                m_UcmUserId(const_cast<SV3_Extract_out0&>(c).m_UcmUserId)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_BingAdsUserId(c.m_BingAdsUserId),
                m_MsAlias(c.m_MsAlias),
                m_UcmUserId(c.m_UcmUserId)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId(const_cast<KeyStruct&>(c).m_BingAdsUserId),
                m_MsAlias(const_cast<KeyStruct&>(c).m_MsAlias, alloc),
                m_UcmUserId(const_cast<KeyStruct&>(c).m_UcmUserId)
            {
            }

            KeyStruct() :
                m_BingAdsUserId(0),
                m_MsAlias(),
                m_UcmUserId(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV3_Extract_out0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_BingAdsUserId, key.m_BingAdsUserId)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_MsAlias, key.m_MsAlias)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_UcmUserId, key.m_UcmUserId)) != 0)
                return r;
            return r;
        }

        static int Compare(SV3_Extract_out0 * n1, SV3_Extract_out0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId, (*n2).m_BingAdsUserId)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias, (*n2).m_MsAlias)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId, (*n2).m_UcmUserId)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(SV3_Extract_out0 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_BingAdsUserId);
            }

            --depth;
            if (depth < 1 && (*p).m_MsAlias.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_MsAlias.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_MsAlias.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_MsAlias.buffer()[depth]));
            }

            depth -= (int) ((*p).m_MsAlias.size() + 1);

            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_UcmUserId);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(SV3_Extract_out0 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            depth -= (int) ((*p).m_MsAlias.size() + 1);
            if (depth < 0)
                return false;
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };




    template<> 
    class KeyComparePolicy<SV12_Extract_Combine_out0,UID_HashJoin_10_FB_1>
    {
    public:
        struct KeyStruct
        {
            int m_BingAdsUserId1;
            FString m_MsAlias2;
            int m_UcmUserId3;

            KeyStruct(SV12_Extract_Combine_out0 & c) :
                m_BingAdsUserId1(c.m_BingAdsUserId1),
                m_MsAlias2(c.m_MsAlias2),
                m_UcmUserId3(c.m_UcmUserId3)
            {
            }

            KeyStruct(const SV12_Extract_Combine_out0 & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId1(const_cast<SV12_Extract_Combine_out0&>(c).m_BingAdsUserId1),
                m_MsAlias2(const_cast<SV12_Extract_Combine_out0&>(c).m_MsAlias2, alloc),
                m_UcmUserId3(const_cast<SV12_Extract_Combine_out0&>(c).m_UcmUserId3)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_BingAdsUserId1(c.m_BingAdsUserId1),
                m_MsAlias2(c.m_MsAlias2),
                m_UcmUserId3(c.m_UcmUserId3)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId1(const_cast<KeyStruct&>(c).m_BingAdsUserId1),
                m_MsAlias2(const_cast<KeyStruct&>(c).m_MsAlias2, alloc),
                m_UcmUserId3(const_cast<KeyStruct&>(c).m_UcmUserId3)
            {
            }

            KeyStruct() :
                m_BingAdsUserId1(0),
                m_MsAlias2(),
                m_UcmUserId3(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"BingAdsUserId1:int,MsAlias2:string,UcmUserId3:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV12_Extract_Combine_out0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_BingAdsUserId1, key.m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_MsAlias2, key.m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_UcmUserId3, key.m_UcmUserId3)) != 0)
                return r;
            return r;
        }

        static int Compare(SV12_Extract_Combine_out0 * n1, SV12_Extract_Combine_out0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId1, (*n2).m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias2, (*n2).m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId3, (*n2).m_UcmUserId3)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(SV12_Extract_Combine_out0 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_BingAdsUserId1);
            }

            --depth;
            if (depth < 1 && (*p).m_MsAlias2.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_MsAlias2.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_MsAlias2.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_MsAlias2.buffer()[depth]));
            }

            depth -= (int) ((*p).m_MsAlias2.size() + 1);

            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_UcmUserId3);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(SV12_Extract_Combine_out0 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            depth -= (int) ((*p).m_MsAlias2.size() + 1);
            if (depth < 0)
                return false;
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };




    template<> 
    class KeyComparePolicy<SV3_Extract_out0,UID_HashJoin_10_0>
    {
    public:
        struct KeyStruct
        {
            int m_BingAdsUserId;
            FString m_MsAlias;
            int m_UcmUserId;

            KeyStruct(SV3_Extract_out0 & c) :
                m_BingAdsUserId(c.m_BingAdsUserId),
                m_MsAlias(c.m_MsAlias),
                m_UcmUserId(c.m_UcmUserId)
            {
            }

            KeyStruct(const SV3_Extract_out0 & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId(const_cast<SV3_Extract_out0&>(c).m_BingAdsUserId),
                m_MsAlias(const_cast<SV3_Extract_out0&>(c).m_MsAlias, alloc),
                m_UcmUserId(const_cast<SV3_Extract_out0&>(c).m_UcmUserId)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_BingAdsUserId(c.m_BingAdsUserId),
                m_MsAlias(c.m_MsAlias),
                m_UcmUserId(c.m_UcmUserId)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId(const_cast<KeyStruct&>(c).m_BingAdsUserId),
                m_MsAlias(const_cast<KeyStruct&>(c).m_MsAlias, alloc),
                m_UcmUserId(const_cast<KeyStruct&>(c).m_UcmUserId)
            {
            }

            KeyStruct() :
                m_BingAdsUserId(0),
                m_MsAlias(),
                m_UcmUserId(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"BingAdsUserId:int,MsAlias:string,UcmUserId:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV3_Extract_out0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_BingAdsUserId, key.m_BingAdsUserId)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_MsAlias, key.m_MsAlias)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_UcmUserId, key.m_UcmUserId)) != 0)
                return r;
            return r;
        }

        static int Compare(SV3_Extract_out0 * n1, SV3_Extract_out0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId, (*n2).m_BingAdsUserId)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias, (*n2).m_MsAlias)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId, (*n2).m_UcmUserId)) != 0)
                return r;
            return r;
        }

    };




    template<> 
    class KeyComparePolicy<SV12_Extract_Combine_out0,UID_HashJoin_10_1>
    {
    public:
        struct KeyStruct
        {
            int m_BingAdsUserId1;
            FString m_MsAlias2;
            int m_UcmUserId3;

            KeyStruct(SV12_Extract_Combine_out0 & c) :
                m_BingAdsUserId1(c.m_BingAdsUserId1),
                m_MsAlias2(c.m_MsAlias2),
                m_UcmUserId3(c.m_UcmUserId3)
            {
            }

            KeyStruct(const SV12_Extract_Combine_out0 & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId1(const_cast<SV12_Extract_Combine_out0&>(c).m_BingAdsUserId1),
                m_MsAlias2(const_cast<SV12_Extract_Combine_out0&>(c).m_MsAlias2, alloc),
                m_UcmUserId3(const_cast<SV12_Extract_Combine_out0&>(c).m_UcmUserId3)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_BingAdsUserId1(c.m_BingAdsUserId1),
                m_MsAlias2(c.m_MsAlias2),
                m_UcmUserId3(c.m_UcmUserId3)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_BingAdsUserId1(const_cast<KeyStruct&>(c).m_BingAdsUserId1),
                m_MsAlias2(const_cast<KeyStruct&>(c).m_MsAlias2, alloc),
                m_UcmUserId3(const_cast<KeyStruct&>(c).m_UcmUserId3)
            {
            }

            KeyStruct() :
                m_BingAdsUserId1(0),
                m_MsAlias2(),
                m_UcmUserId3(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"BingAdsUserId1:int,MsAlias2:string,UcmUserId3:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(SV12_Extract_Combine_out0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_BingAdsUserId1, key.m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_MsAlias2, key.m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare(row.m_UcmUserId3, key.m_UcmUserId3)) != 0)
                return r;
            return r;
        }

        static int Compare(SV12_Extract_Combine_out0 * n1, SV12_Extract_Combine_out0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId1, (*n2).m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias2, (*n2).m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId3, (*n2).m_UcmUserId3)) != 0)
                return r;
            return r;
        }

    };



#if defined(COMPILE_NATIVE)
    template<>
    class RowHashPolicy<SV3_Extract_out0,UID_HashJoin_10>
    {
    public:
        static __int64 Hash(SV3_Extract_out0* row)
        {
            ScopeRowHasher hasher;
            hasher.HashColumnValue<int> ((*row).m_BingAdsUserId);
            hasher.HashColumnValue<FString> ((*row).m_MsAlias);
            hasher.HashColumnValue<int> ((*row).m_UcmUserId);
            return hasher.ComputeHashCode();
        }

        INLINE static int Bucket(SV3_Extract_out0* row, int bucketCount)
        {
            return ScopeRowHasher::ComputeBucket(Hash(row), bucketCount);
        }
    };

#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)




#if defined(COMPILE_NATIVE)
    template<> 
    class CombinerPolicy<UID_HashJoin_10> 
    {
    public:
        typedef KeyComparePolicy<SV3_Extract_out0,UID_HashJoin_10_0> LeftKeyPolicy;
        typedef KeyComparePolicy<SV12_Extract_Combine_out0,UID_HashJoin_10_1> RightKeyPolicy;

        static constexpr unsigned MaxPerKeyCrossSizeLimit = 0;

        static LONGLONG JoinerMemQuota()
        {
            return 262144000ULL;
        }

        // compare key from left and right schema object
        static int Compare(const SV3_Extract_out0 * left, const SV12_Extract_Combine_out0 * right)
        {
            int r = 0;
            SV3_Extract_out0 * n1 = const_cast<SV3_Extract_out0 *>(left);
            SV12_Extract_Combine_out0 * n2 = const_cast<SV12_Extract_Combine_out0 *>(right);

            if ((r = ScopeTypeCompare((*n1).m_BingAdsUserId, (*n2).m_BingAdsUserId1)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_MsAlias, (*n2).m_MsAlias2)) != 0)
                return r;
            if ((r = ScopeTypeCompare((*n1).m_UcmUserId, (*n2).m_UcmUserId3)) != 0)
                return r;
            
            // Everything matches
            return 0;
        }

        static void CopyRow(SV3_Extract_out0 * left, SV12_Extract_Combine_out0 * right, HashJoin_10_Data0 * out)
        {
                (*out).m_BingAdsUserId = (*left).m_BingAdsUserId;
                (*out).m_MsAlias = (*left).m_MsAlias;
                (*out).m_UcmUserId = (*left).m_UcmUserId;
                (*out).m_NumofMonth = (*right).m_NumofMonth;
                (*out).m_LastMonth = (*right).m_LastMonth;
                (*out).m_TotalUsage = (*right).m_TotalUsage;
                (*out).m_NumofWeek = (*right).m_NumofWeek;
        }

        static void CopyLeftRow(SV3_Extract_out0 * left, HashJoin_10_Data0 * out)
        {
            (*out).m_BingAdsUserId = (*left).m_BingAdsUserId;
            (*out).m_MsAlias = (*left).m_MsAlias;
            (*out).m_UcmUserId = (*left).m_UcmUserId;
        }

        static void NullifyLeftSide(HashJoin_10_Data0 * out)
        {
            (*out).m_MsAlias.SetNull();
        }

        static void CopyRightRow(SV12_Extract_Combine_out0 * right, HashJoin_10_Data0 * out)
        {
            (*out).m_NumofMonth = (*right).m_NumofMonth;
            (*out).m_LastMonth = (*right).m_LastMonth;
            (*out).m_TotalUsage = (*right).m_TotalUsage;
            (*out).m_NumofWeek = (*right).m_NumofWeek;
        }

        static void NullifyRightSide(HashJoin_10_Data0 * out)
        {
            (*out).m_NumofMonth.SetNull();
            (*out).m_LastMonth.SetNull();
            (*out).m_TotalUsage.SetNull();
            (*out).m_NumofWeek.SetNull();
        }
    };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
    template<>
    class HashCombinerWithFallbackPolicy<SV3_Extract_out0, SV12_Extract_Combine_out0, HashJoin_10_Data0, UID_HashJoin_10>
    {
    public:
        static constexpr int ProbeSorterUID = UID_HashJoin_10_FB_0;
        static constexpr int BuildSorterUID = UID_HashJoin_10_FB_1;
        typedef StdSort<SV3_Extract_out0> ProbeSorterAlgorithm;
        typedef StdSort<SV12_Extract_Combine_out0> BuildSorterAlgorithm;
    };

    template <>
    class HashCombinerPolicyV2<SV3_Extract_out0, SV12_Extract_Combine_out0, HashJoin_10_Data0, UID_HashJoin_10>
    {
    public:
        typedef HashCombinerPolicyV2<SV3_Extract_out0, SV12_Extract_Combine_out0, HashJoin_10_Data0, UID_HashJoin_10> P;

        typedef HashCmbnKey_HashJoin_8 KeySchema;
        typedef HashCmbnVal_HashJoin_10 ValueSchema;

        // >> define hash & equal functions
        struct Hash
        {
            const INT64 m_seed;

            Hash() : m_seed((INT64)0) {}
            Hash(INT64 seed) : m_seed(seed) {}

            INT64 operator () (const HashCmbnKey_HashJoin_8& schema) const
            {
                INT64 result = m_seed;
                    result += ScopeHash(schema.m_BingAdsUserId_BingAdsUserId1);
                    result += ScopeHash(schema.m_MsAlias_MsAlias2);
                    result += ScopeHash(schema.m_UcmUserId_UcmUserId3);
                
                return result;
            }
        };

        struct BuildHash
        {
            const INT64 m_seed;

            BuildHash() : m_seed((INT64)0) {}
            BuildHash(INT64 seed) : m_seed(seed) {}

            INT64 operator () (const SV12_Extract_Combine_out0& schema) const
            {
                INT64 result = m_seed;
                    result += ScopeHash(schema.m_BingAdsUserId1);
                    result += ScopeHash(schema.m_MsAlias2);
                    result += ScopeHash(schema.m_UcmUserId3);
                
                return result;
            }
        };

        struct ProbeHash
        {
            const INT64 m_seed;

            ProbeHash() : m_seed((INT64)0) {}
            ProbeHash(INT64 seed) : m_seed(seed) {}

            INT64 operator () (const SV3_Extract_out0& schema) const
            {
                INT64 result = m_seed;
                    result += ScopeHash(schema.m_BingAdsUserId);
                    result += ScopeHash(schema.m_MsAlias);
                    result += ScopeHash(schema.m_UcmUserId);
                
                return result;
            }
        };

        struct EqualTo
        {
            bool operator () (const HashCmbnKey_HashJoin_8& left, const HashCmbnKey_HashJoin_8& right) const
            {
                if (!ScopeTypeCompare_EqualEqual(left.m_BingAdsUserId_BingAdsUserId1, right.m_BingAdsUserId_BingAdsUserId1)) return false;
                if (!ScopeTypeCompare_EqualEqual(left.m_MsAlias_MsAlias2, right.m_MsAlias_MsAlias2)) return false;
                if (!ScopeTypeCompare_EqualEqual(left.m_UcmUserId_UcmUserId3, right.m_UcmUserId_UcmUserId3)) return false;
                return true;
            }
        };
        struct ProbeEqualTo
        {
            bool operator () (const SV3_Extract_out0& left, const HashCmbnKey_HashJoin_8& right) const
            {
                if (!ScopeTypeCompare_EqualEqual(left.m_BingAdsUserId, right.m_BingAdsUserId_BingAdsUserId1)) return false;
                if (!ScopeTypeCompare_EqualEqual(left.m_MsAlias, right.m_MsAlias_MsAlias2)) return false;
                if (!ScopeTypeCompare_EqualEqual(left.m_UcmUserId, right.m_UcmUserId_UcmUserId3)) return false;
                return true;
            }
        };
        static INT64* Seed()
        {
            static INT64 seed[] { 31607, 40529 };
            return seed;
        }

        static BuildHash* BuildHashes()
        {
            static BuildHash hashes[] { BuildHash(Seed()[0]), BuildHash(Seed()[1]) };
            return hashes;
        }

        static ProbeHash* ProbeHashes()
        {
            static ProbeHash hashes[] { ProbeHash(Seed()[0]), ProbeHash(Seed()[1]) };
            return hashes;
        }

        static constexpr size_t s_seedCnt{ 2 };

        // << define hash & equal functions

        // >> define spilling
        struct Spilling
        {
            static constexpr size_t s_bufferSize{ 4 * 1024 * 1024 }; //4MB
            static constexpr size_t s_bufferCnt{ 2 };
            static constexpr bool s_disable{ false };
            static constexpr bool s_raiseUserError{ false };
        };
        // << define spilling

        // >> define constants
        static constexpr size_t s_memoryQuota{ 1073741824ULL }; // Cosmos default is 2GB

        // the maximum number of buckets in the hashtable is defined as 
        // s_directorySize * 2^s_segmentSizeExponent => 67 108 864
        // s_directorySize has to be a power of two
        static constexpr size_t s_directorySize{ 4096 };
        static constexpr size_t s_segmentSizeExponent{ 14 }; // 16384 bucket per segment

         // number of hashtables used in the join, the data is spilled one hashtable at a time
        static constexpr size_t s_hashtableCntExponent{ 2 }; // 4 hashtables

         // initial number of buckets per hashtable
         // s_initialSize has to be a power of two
        static constexpr size_t s_initialSize { 128 * (1 << s_segmentSizeExponent) };

        // the length of the segment of the value list is defined as
        // 2^s_valueListSegmentSizeExponent => 1
        static constexpr size_t s_valueListSegmentSizeExponent{ 0 };

        static constexpr size_t s_maxPerKeyCrossSizeLimit{ 0 };
        // << define constants

        typedef STLIncrementalAllocator<char> CharAllocator;
        typedef GranularList<ValueSchema*, s_valueListSegmentSizeExponent, CharAllocator> UnderlyingValue;
        typedef UnderlyingValue Value;
        typedef Value::Iterator ValueIterator;

        template <typename Item, typename CharAllocator>
        struct HashtablePolicy : public SlimHashtableLayoutPolicy<Item, CharAllocator>::Type
        {
            struct BucketArrayTraits
            {
                static constexpr size_t s_directorySize{ P::s_directorySize };
                static constexpr size_t s_segmentSizeExponent{ P::s_segmentSizeExponent };
            };
        };

        typedef SlimHashMap<KeySchema, Value, HashtablePolicy, Hash, EqualTo> Hashtable;

        static constexpr HashCombinerValuesPerKeyCountV2 s_valuesPerKeyCount = HashCombinerValuesPerKeyCountV2::MANY;

        static void UpdateValueList(CharAllocator& alloc, Value& valueList, ValueSchema* value)
        {
            valueList.EmplaceFront(alloc, value);
        }

        static ValueIterator ValueListBegin(Value& valueList)
        {
            return valueList.Begin();
        }
        
        static ValueIterator ValueListEnd(Value& valueList)
        {
            return valueList.End();
        }
        
        static size_t ValueListSize(const Value& valueList)
        {
            return valueList.Size();
        }

        static size_t IncrementValueListStats(Value& valueList)
        {
            return 0;
        }

    
        // Shallow copy probe and build schema fields to the output
        static void CopyBoth(const SV3_Extract_out0 & probe, const ValueSchema * build, HashJoin_10_Data0 & output)
        {
            // copy probe
            output.m_BingAdsUserId = probe.m_BingAdsUserId;
            output.m_MsAlias = probe.m_MsAlias;
            output.m_UcmUserId = probe.m_UcmUserId;

            // copy build
            output.m_NumofMonth = (*build).m_NumofMonth;
            output.m_LastMonth = (*build).m_LastMonth;
            output.m_TotalUsage = (*build).m_TotalUsage;
            output.m_NumofWeek = (*build).m_NumofWeek;
        }

        // Shallow copy probe schema fields to the output and nullify all the rest
        static void CopyProbeAndNullifyBuild(const SV3_Extract_out0 & probe, HashJoin_10_Data0 & output)
        {
            // copy probe
            output.m_BingAdsUserId = probe.m_BingAdsUserId;
            output.m_MsAlias = probe.m_MsAlias;
            output.m_UcmUserId = probe.m_UcmUserId;

            // nullify build
            output.m_NumofMonth.SetNull();
            output.m_LastMonth.SetNull();
            output.m_TotalUsage.SetNull();
            output.m_NumofWeek.SetNull();
        }

         static void DeepCopyBuildRowToKeyValue(const SV12_Extract_Combine_out0 & row, KeySchema & key, ValueSchema * value, IncrementalAllocator* alloc)
         {
            // copy key
           key.m_BingAdsUserId_BingAdsUserId1 = row.m_BingAdsUserId1;
            FString tmp_MsAlias2(row.m_MsAlias2, alloc);
           key.m_MsAlias_MsAlias2 = tmp_MsAlias2;
           key.m_UcmUserId_UcmUserId3 = row.m_UcmUserId3;
            // copy value
            (*value).m_NumofMonth = row.m_NumofMonth;
            FString tmp_LastMonth(row.m_LastMonth, alloc);
            (*value).m_LastMonth = tmp_LastMonth;
            (*value).m_TotalUsage = row.m_TotalUsage;
            (*value).m_NumofWeek = row.m_NumofWeek;
         }

         static void CopyKeyValueToBuildRow(const KeySchema & key, const ValueSchema * value, SV12_Extract_Combine_out0 & row)
         {
            // copy key
           row.m_BingAdsUserId1 = key.m_BingAdsUserId_BingAdsUserId1;
           row.m_MsAlias2 = key.m_MsAlias_MsAlias2;
           row.m_UcmUserId3 = key.m_UcmUserId_UcmUserId3;
            // copy value
            row.m_NumofMonth = (*value).m_NumofMonth;
            row.m_LastMonth = (*value).m_LastMonth;
            row.m_TotalUsage = (*value).m_TotalUsage;
            row.m_NumofWeek = (*value).m_NumofWeek;
         }

        static void InsertOrUpdate(Hashtable& ht, const SV12_Extract_Combine_out0 & row, INT64 hash, IncrementalAllocator& alloc, CharAllocator& calloc)
        {
            KeySchema key;
            ValueSchema* value = new (alloc.Allocate(sizeof(ValueSchema))) ValueSchema();
            DeepCopyBuildRowToKeyValue(row, key, value, &alloc);

            Value vlist;
            auto it = ht.InsertWithPrecomputedHash(hash, { key, vlist });
            UpdateValueList(calloc, it.first->second, value);
        }
    };

#endif // defined(COMPILE_NATIVE)





    template<>
    class RowTransformPolicy<Process_11_Data0, Process_12_Data0, UID_Process_12>
    {
    public:
        static bool FilterTransformRow(Process_11_Data0 & input, Process_12_Data0 & output, IncrementalAllocator * alloc)
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
    struct ManagedUDO<UID_Process_12>
    {
        typedef ScopeRuntime::Processor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Process_12());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{ L"Jul 5 2" })));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Process_12, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_BA9089D6CEAA8BB5();
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
    class InteropToManagedRowPolicy<Process_11_Data0, UID_Process_12>
    {
    public:
        static void Marshal(Process_11_Data0& nativeRow, ScopeRuntime::Row^% managedRow, InteropAllocator * alloc)
        {
            alloc->CopyToManagedColumn(nativeRow.m_BingAdsUserId, managedRow[0], 0);
            alloc->CopyToManagedColumn(nativeRow.m_MsAlias, managedRow[1], 1);
            alloc->CopyToManagedColumn(nativeRow.m_UcmUserId, managedRow[2], 2);
            alloc->CopyToManagedColumn(nativeRow.m_NumofMonth, managedRow[3], 3);
            alloc->CopyToManagedColumn(nativeRow.m_LastMonth, managedRow[4], 4);
            alloc->CopyToManagedColumn(nativeRow.m_NumofWeek, managedRow[5], 5);
            alloc->CopyToManagedColumn(nativeRow.m_TotalUsage, managedRow[6], 6);
        }
    };
    template<>
    class InteropToNativeRowPolicy<Process_12_Data0, UID_Process_12>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Process_12_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_BingAdsUserId, managedRow[0]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_MsAlias, managedRow[1]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_UcmUserId, managedRow[2]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_FreqSegment, managedRow[3]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_NumofMonth, managedRow[4]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_LastMonth, managedRow[5]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_NumofWeek, managedRow[6]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_TotalUsage, managedRow[7]->Integer, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV13_Cmbn_Split : Extractor<SV3_Extract_out0, BinaryExtractPolicy<SV3_Extract_out0>, BinaryInputStream> { using Extractor<SV3_Extract_out0, BinaryExtractPolicy<SV3_Extract_out0>, BinaryInputStream>::Extractor; };
struct ExtractorType2_SV13_Cmbn_Split : Extractor<SV12_Extract_Combine_out0, BinaryExtractPolicy<SV12_Extract_Combine_out0>, BinaryInputStream> { using Extractor<SV12_Extract_Combine_out0, BinaryExtractPolicy<SV12_Extract_Combine_out0>, BinaryInputStream>::Extractor; };
struct CombinerType_HashJoin_10 : HashCombinerWithFallback<ExtractorType1_SV13_Cmbn_Split, SV3_Extract_out0, ExtractorType2_SV13_Cmbn_Split, SV12_Extract_Combine_out0, HashJoin_10_Data0, HashLeftOuterJoinerV2, LeftOuterJoiner, UID_HashJoin_10> { using HashCombinerWithFallback<ExtractorType1_SV13_Cmbn_Split, SV3_Extract_out0, ExtractorType2_SV13_Cmbn_Split, SV12_Extract_Combine_out0, HashJoin_10_Data0, HashLeftOuterJoinerV2, LeftOuterJoiner, UID_HashJoin_10>::HashCombinerWithFallback; };
struct FilterTransformerType_Process_11 : FilterTransformer<CombinerType_HashJoin_10, HashJoin_10_Data0, Process_11_Data0, UID_Process_11> { using FilterTransformer<CombinerType_HashJoin_10, HashJoin_10_Data0, Process_11_Data0, UID_Process_11>::FilterTransformer; };
struct ProcessorType_Process_12 : ScopeProcessor<Process_11_Data0, Process_12_Data0> { using ScopeProcessor<Process_11_Data0, Process_12_Data0>::ScopeProcessor; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV13_Combine_Split_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;

        // ExtractorType1_SV13_Cmbn_Split: Extractor<SV3_Extract_out0, BinaryExtractPolicy<SV3_Extract_out0>, BinaryInputStream>
        unique_ptr<ExtractorType1_SV13_Cmbn_Split> extractor_0_ptr= make_unique<ExtractorType1_SV13_Cmbn_Split>(inputs[0], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV3_Extract_out0);
        ExtractorType1_SV13_Cmbn_Split * extractor_0 = extractor_0_ptr.get();
        ULONG extractor_0_count = 1;

        // ExtractorType2_SV13_Cmbn_Split: Extractor<SV12_Extract_Combine_out0, BinaryExtractPolicy<SV12_Extract_Combine_out0>, BinaryInputStream>
        unique_ptr<ExtractorType2_SV13_Cmbn_Split> extractor_1_ptr= make_unique<ExtractorType2_SV13_Cmbn_Split>(inputs[1], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV12_Extract_Combine_out0);
        ExtractorType2_SV13_Cmbn_Split * extractor_1 = extractor_1_ptr.get();
        ULONG extractor_1_count = 1;

        // CombinerType_HashJoin_10: HashCombinerWithFallback<ExtractorType1_SV13_Cmbn_Split, SV3_Extract_out0, ExtractorType2_SV13_Cmbn_Split, SV12_Extract_Combine_out0, HashJoin_10_Data0, HashLeftOuterJoinerV2, LeftOuterJoiner, UID_HashJoin_10>
        unique_ptr<CombinerType_HashJoin_10> combiner_HashJoin_10_ptr;
        combiner_HashJoin_10_ptr.reset(new CombinerType_HashJoin_10(extractor_0, extractor_1, UID_HashJoin_10, 0));

        CombinerType_HashJoin_10 * combiner_HashJoin_10 = combiner_HashJoin_10_ptr.get();
        ULONG combiner_HashJoin_10_count = 1;

        // FilterTransformerType_Process_11: FilterTransformer<CombinerType_HashJoin_10, HashJoin_10_Data0, Process_11_Data0, UID_Process_11>
        unique_ptr<FilterTransformerType_Process_11> filterTransformer_Process_11_ptr (new FilterTransformerType_Process_11(combiner_HashJoin_10, UID_Process_11));
        FilterTransformerType_Process_11 * filterTransformer_Process_11 = filterTransformer_Process_11_ptr.get();
        ULONG filterTransformer_Process_11_count = 1;
        unique_ptr<OperatorDelegate<Process_11_Data0>> delegate_filterTransformer_Process_11_ptr (new OperatorDelegate<Process_11_Data0>(filterTransformer_Process_11));
        OperatorDelegate<Process_11_Data0> * delegate_filterTransformer_Process_11 = delegate_filterTransformer_Process_11_ptr.get();
        ULONG delegate_filterTransformer_Process_11_count = 1;

        // ProcessorType_Process_12: ScopeProcessor<Process_11_Data0, Process_12_Data0>
        unique_ptr<ProcessorType_Process_12> processor_Process_12_ptr (new ProcessorType_Process_12(ScopeProcessorManagedFactory::Make<Process_11_Data0,Process_12_Data0,UID_Process_12>(delegate_filterTransformer_Process_11), delegate_filterTransformer_Process_11, UID_Process_12));
        ProcessorType_Process_12 * processor_Process_12 = processor_Process_12_ptr.get();
        ULONG processor_Process_12_count = 1;

        using OutputterType3_SV13_Cmbn_Split = SStreamOutputter<ProcessorType_Process_12, Process_12_Data0, UID_SStreamOutput_13>;

        // Construct operator and initialize it
        unique_ptr<OutputterType3_SV13_Cmbn_Split> outputter_SStreamOutput_13_ptr(new OutputterType3_SV13_Cmbn_Split(processor_Process_12, &outputs[0], 1, outputs[1].outputFileName, false, UID_SStreamOutput_13, false));
        OutputterType3_SV13_Cmbn_Split * outputter_SStreamOutput_13 = outputter_SStreamOutput_13_ptr.get();

        if (argv != nullptr && argc > 0)
        {
            try
            {
                int sequenceNumber = GetSequenceNumber(argv, argc);
                outputter_SStreamOutput_13->SetSequenceNumber(sequenceNumber);
            }
            catch(const RuntimeException&)
            {
                // Sequence number will remain 0 in outputter_SStreamOutput_13.
            }
        }
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SStreamOutput_13) };

        try
        {
            // Init operator chain
            outputter_SStreamOutput_13->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_12_Data0 row;
            outputter_SStreamOutput_13->GetNextRow(row);

            // Close operator chain
            outputter_SStreamOutput_13->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SStreamOutput_13->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
template ScopeProcessorManaged<Process_11_Data0, Process_12_Data0> * ScopeEngine::ScopeProcessorManagedFactory::Make<Process_11_Data0, Process_12_Data0, UID_Process_12>(OperatorDelegate<Process_11_Data0>*);
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV13_Combine_Split
#pragma region SV14_Aggregate
#if defined(COMPILE_SV14_AGGREGATE) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<Part_GetSStream_0,UID_SStreamMetadataOutput_15>
    {
    public:
        struct KeyStruct
        {

            KeyStruct(Part_GetSStream_0 & c) 

            {
            }

            KeyStruct(const Part_GetSStream_0 & c, IncrementalAllocator * alloc) 

            {
            }

            KeyStruct(KeyStruct & c) 

            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) 

            {
            }

            KeyStruct() 

            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {
                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Part_GetSStream_0 & row, KeyType & key)
        {
            int r = 0;
            return r;
        }

        static int Compare(Part_GetSStream_0 * n1, Part_GetSStream_0 * n2)
        {
            int r = 0;
            return r;
        }

    };



#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV14_Agg : SStreamMetadataExtractor<Process_12_Data0> { using SStreamMetadataExtractor<Process_12_Data0>::SStreamMetadataExtractor; };
struct MetadataAggregateType_MetadataAggregate_14 : Merger<ExtractorType1_SV14_Agg, Process_12_Data0, ScopeUnionAll<ExtractorType1_SV14_Agg, Process_12_Data0>, UID_MetadataAggregate_14> { using Merger<ExtractorType1_SV14_Agg, Process_12_Data0, ScopeUnionAll<ExtractorType1_SV14_Agg, Process_12_Data0>, UID_MetadataAggregate_14>::Merger; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV14_Aggregate_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // remove the empty stream
        // For the case "PARTITION_NOT_EXIST", the output stream is blank. So here the input stream may be blank.
        int inputIdx2 = 0;
        
        for (int inputIdx = 0; inputIdx < inputCnt; ++inputIdx)
        {
            if(inputs[inputIdx].length == 0)
            {
                continue;
            }
            inputs[inputIdx2] = inputs[inputIdx];
            ++inputIdx2;
        }
        inputCnt =inputIdx2;

        // ExtractorType1_SV14_Agg: SStreamMetadataExtractor<Process_12_Data0>
        unique_ptr<unique_ptr<ExtractorType1_SV14_Agg>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV14_Agg>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV14_Agg(inputs[i], i, false, false, UID_SV13_Combine_Split_out1));
        }

    ExtractorType1_SV14_Agg ** extractor_0 = (ExtractorType1_SV14_Agg **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // MetadataAggregateType_MetadataAggregate_14: Merger<ExtractorType1_SV14_Agg, Process_12_Data0, ScopeUnionAll<ExtractorType1_SV14_Agg, Process_12_Data0>, UID_MetadataAggregate_14>
        unique_ptr<MetadataAggregateType_MetadataAggregate_14> metadataAggregate_MetadataAggregate_14_ptr(new MetadataAggregateType_MetadataAggregate_14(extractor_0, extractor_0_count, false, UID_MetadataAggregate_14));
        MetadataAggregateType_MetadataAggregate_14* metadataAggregate_MetadataAggregate_14 = metadataAggregate_MetadataAggregate_14_ptr.get();

        using OutputterType2_SV14_Agg = SStreamMetadataOutputter<MetadataAggregateType_MetadataAggregate_14, Process_12_Data0, Part_GetSStream_0, UID_SStreamMetadataOutput_15>;
        unique_ptr<OutputterType2_SV14_Agg> outputter_SStreamMetadataOutput_15_ptr(new OutputterType2_SV14_Agg(metadataAggregate_MetadataAggregate_14, outputs[0].outputFileName, "", false, false, 0, UID_SStreamMetadataOutput_15));
        OutputterType2_SV14_Agg * outputter_SStreamMetadataOutput_15 = outputter_SStreamMetadataOutput_15_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SStreamMetadataOutput_15) };

        try
        {
            // Init operator chain
            outputter_SStreamMetadataOutput_15->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_12_Data0 row;
            outputter_SStreamMetadataOutput_15->GetNextRow(row);

            // Close operator chain
            outputter_SStreamMetadataOutput_15->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SStreamMetadataOutput_15->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV14_Aggregate
#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)
#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


std::array<const char *, 3> SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_columnNames =
{{"Column1", "Column2", "Column3"}};
std::array<const char *, 3> SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_columnTypes =
{{"string", "string", "string"}};
std::array<BYTE, 3> SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_dataColumnSizes =
{{0, 0, 0}};
std::array<BYTE, 3> SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_indexColumnSizes =
{{8, 8, 4}};
UINT* SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_dataPageSortKeys = nullptr;
const char** SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_dataPageSortOrders = nullptr;
const char* SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_dataPageSortUniq = nullptr;
const char SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_partitionType[] =
"RandomPartition";
UINT *      SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_partitionKeys = nullptr;
const char **  SStreamV3OutputPolicy<GetSStream_0_Data0, UID_SStreamOutput_1>::m_partitionOrders = nullptr;

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV2_AGGREGATE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV2_AGGREGATE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV3_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV3_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV4_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

std::array<const char *, 7> SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_columnNames =
{{"UserId", "Start", "Region", "Query", "Duration", "Urls", "ClickedUrls"}};
std::array<const char *, 7> SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_columnTypes =
{{"int", "DateTime", "string", "string", "int", "string", "string"}};
std::array<BYTE, 7> SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_dataColumnSizes =
{{4, 8, 0, 0, 4, 0, 0}};
std::array<BYTE, 3> SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_indexColumnSizes =
{{8, 8, 4}};
UINT* SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_dataPageSortKeys = nullptr;
const char** SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_dataPageSortOrders = nullptr;
const char* SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_dataPageSortUniq = nullptr;
const char SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_partitionType[] =
"RandomPartition";
UINT *      SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_partitionKeys = nullptr;
const char **  SStreamV3OutputPolicy<Extract_16_Data0, UID_SV4_Extract_Split_out0>::m_partitionOrders = nullptr;

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV4_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV5_AGGREGATE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV5_AGGREGATE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV6_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)






#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV6_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV7_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV7_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV8_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV8_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV9_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV9_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV10_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV10_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV11_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)



#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV11_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV12_EXTRACT_COMBINE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)







#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV12_EXTRACT_COMBINE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV13_COMBINE_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

std::array<const char *, 8> SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_columnNames =
{{"BingAdsUserId", "MsAlias", "UcmUserId", "FreqSegment", "NumofMonth", "LastMonth", "NumofWeek", "TotalUsage"}};
std::array<const char *, 8> SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_columnTypes =
{{"int", "string", "int", "string", "int", "string", "int", "int"}};
std::array<BYTE, 8> SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_dataColumnSizes =
{{4, 0, 4, 0, 4, 0, 4, 4}};
std::array<BYTE, 3> SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_indexColumnSizes =
{{8, 8, 4}};
UINT* SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_dataPageSortKeys = nullptr;
const char** SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_dataPageSortOrders = nullptr;
const char* SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_dataPageSortUniq = nullptr;
const char SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_partitionType[] =
"RandomPartition";
UINT *      SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_partitionKeys = nullptr;
const char **  SStreamV3OutputPolicy<Process_12_Data0, UID_SStreamOutput_13>::m_partitionOrders = nullptr;

#pragma warning(push)
#pragma warning(disable:4592)
FString RowTransformPolicy<HashJoin_10_Data0, Process_11_Data0, UID_Process_11>::staticconstant_0;
#pragma warning(pop)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV13_COMBINE_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV14_AGGREGATE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV14_AGGREGATE) || defined(COMPILE_ALL_VERTICES)
// Empty footer
