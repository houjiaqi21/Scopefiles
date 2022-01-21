using Microsoft.Analytics.Interfaces;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Text;
using System.Reflection;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading;
using System.Runtime.Serialization;
using System.Linq;
using Microsoft.SCOPE.Types;
using ScopeRuntime;
using System.Runtime.Versioning;
[assembly:TargetFramework(".NETFramework,Version=v4.7.2", FrameworkDisplayName = ".NET Framework, Version 4.7.2")]

public class ___Scope_Generated_Classes___
{
	public static int __RuntimeVersion__ = 0;
	public static int __WriteSStreamVersion__ = 3;
	public static bool __BondIntermediates__ = false;
	private delegate ColumnData ColumnDataCtor();
#region ==BEGIN USER CODE==
#endregion ==END USER CODE==

	public class Row_F7146980BD03F3F8 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UserId", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.DateTime, typeof(System.DateTime), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Region", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Duration", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Urls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.IntegerColumnData s0_UserId;
		public ScopeRuntime.IntegerColumnData UserId
		{
			get { return s0_UserId; }
			set 
			{
				s0_UserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DateTimeColumnData s0_Start;
		public ScopeRuntime.DateTimeColumnData Start
		{
			get { return s0_Start; }
			set 
			{
				s0_Start = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Region;
		public ScopeRuntime.StringColumnData Region
		{
			get { return s0_Region; }
			set 
			{
				s0_Region = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Query;
		public ScopeRuntime.StringColumnData Query
		{
			get { return s0_Query; }
			set 
			{
				s0_Query = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Duration;
		public ScopeRuntime.IntegerColumnData Duration
		{
			get { return s0_Duration; }
			set 
			{
				s0_Duration = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Urls;
		public ScopeRuntime.StringColumnData Urls
		{
			get { return s0_Urls; }
			set 
			{
				s0_Urls = value;
				_columns[5] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_ClickedUrls;
		public ScopeRuntime.StringColumnData ClickedUrls
		{
			get { return s0_ClickedUrls; }
			set 
			{
				s0_ClickedUrls = value;
				_columns[6] = value;
			}
		}
		public Row_F7146980BD03F3F8(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_F7146980BD03F3F8(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_F7146980BD03F3F8() : base(BuildSchema(), BuildColumnData())
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		private static Schema BuildSchema()
		{
			Schema schema = new Schema();
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item3));
				}
				else
				{
					schema.Add(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return schema;
		}
		private static ColumnData[] BuildColumnData()
		{
			ColumnData[] columnData = new ColumnData[_columnTable.Length];
			for (int i = 0; i < _columnTable.Length; ++i)
			{
				if (_columnTable[i].Item5 == null)
				{
					columnData[i] = _columnTable[i].Item4 != null ? _columnTable[i].Item4() : ColumnDataFactory.Create(_columnTable[i].Item2);
				}
				else
				{
					columnData[i] = ColumnDataFactory.Create(new ScopeRuntime.ColumnInfo(_columnTable[i].Item1, _columnTable[i].Item5));
				}
			}
			return columnData;
		}
		public override ColumnData this[int index]
		{
			get { return _columns[index]; }
			set
			{
				_columns[index] = value;

				//  We also need to reset the property
				switch (index)
				{

					case 0:
					{
						s0_UserId = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 1:
					{
						s0_Start = (ScopeRuntime.DateTimeColumnData)value;
						break;
					}
					case 2:
					{
						s0_Region = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 3:
					{
						s0_Query = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 4:
					{
						s0_Duration = (ScopeRuntime.IntegerColumnData)value;
						break;
					}
					case 5:
					{
						s0_Urls = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 6:
					{
						s0_ClickedUrls = (ScopeRuntime.StringColumnData)value;
						break;
					}
				}
			}
		}
		public override void Serialize(BinaryWriter writer)
		{
			byte[] ___masking___ = new byte[1];
			___masking___[0] = 1;

			bool hasNull = false;
			if (s0_Region.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Urls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_ClickedUrls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			s0_UserId.Serialize(writer);
			s0_Start.Serialize(writer);
			if (!s0_Region.IsNull())
			{
				s0_Region.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			s0_Duration.Serialize(writer);
			if (!s0_Urls.IsNull())
			{
				s0_Urls.Serialize(writer);
			}
			if (!s0_ClickedUrls.IsNull())
			{
				s0_ClickedUrls.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_UserId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				s0_Region.Deserialize(reader);
				s0_Query.Deserialize(reader);
				s0_Duration.Deserialize(reader);
				s0_Urls.Deserialize(reader);
				s0_ClickedUrls.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_UserId.Deserialize(reader);
				s0_Start.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Region.Deserialize(reader);
				}
				else
				{
					s0_Region.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				s0_Duration.Deserialize(reader);
				if ((___masking___[0] & 8) != 8)
				{
					s0_Urls.Deserialize(reader);
				}
				else
				{
					s0_Urls.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_ClickedUrls.Deserialize(reader);
				}
				else
				{
					s0_ClickedUrls.SetNull();
				}
			}
		}
	}

	public class ScopeSStreamOutput_1 : SStreamOutputter
	{
		Row_F7146980BD03F3F8 columnGroupRow_0 = new Row_F7146980BD03F3F8 (new Schema("UserId:int,Start:DateTime,Region:string,Query:string,Duration:int,Urls:string,ClickedUrls:string"));
		public ScopeSStreamOutput_1()
		{
			_isSerial = true;
			_blockSize = 4194304;
		}
		public override void OutputRow (Row row)
		{
			columnGroupRow_0.UserId = ((Row_F7146980BD03F3F8)row).UserId;
			columnGroupRow_0.Start = ((Row_F7146980BD03F3F8)row).Start;
			columnGroupRow_0.Region = ((Row_F7146980BD03F3F8)row).Region;
			columnGroupRow_0.Query = ((Row_F7146980BD03F3F8)row).Query;
			columnGroupRow_0.Duration = ((Row_F7146980BD03F3F8)row).Duration;
			columnGroupRow_0.Urls = ((Row_F7146980BD03F3F8)row).Urls;
			columnGroupRow_0.ClickedUrls = ((Row_F7146980BD03F3F8)row).ClickedUrls;
			_writers[0].AppendRow (columnGroupRow_0 );
			
		}
	}


	public static System.Type[] __UdtTypeTable__ =
	{
		
	};

	public static class __OperatorFactory__
	{
	}
}

	static public class UDTExtensionWrapper
	{
                public static T Create<T>() where T : new() 
                { 
                    return new T(); 
                }

                private static readonly System.Collections.Generic.Dictionary<System.Collections.Generic.IEqualityComparer<string>, byte> StringComparerToByteMap =
                    new System.Collections.Generic.Dictionary<System.Collections.Generic.IEqualityComparer<string>, byte>()
                    {
                        {System.Collections.Generic.EqualityComparer<string>.Default, 0},
                        {System.StringComparer.CurrentCulture, 1},
                        {System.StringComparer.CurrentCultureIgnoreCase, 2},
                        {System.StringComparer.InvariantCulture, 3},
                        {System.StringComparer.InvariantCultureIgnoreCase, 4},
                        {System.StringComparer.Ordinal, 5},
                        {System.StringComparer.OrdinalIgnoreCase, 6},
                    };

                private static readonly System.Collections.Generic.Dictionary<byte, System.Collections.Generic.IEqualityComparer<string>> ByteToStringComparerMap =
                    System.Linq.Enumerable.ToDictionary(StringComparerToByteMap, kvp => kvp.Value, kvp => kvp.Key);

                public static void Read(BinaryValueReader reader, out System.StringComparer value)
                {
                    byte comparerKey;
                    reader.Read(out comparerKey);
                    value = ByteToStringComparerMap[comparerKey] as System.StringComparer;
                }

                public static void Write(BinaryValueWriter writer, System.StringComparer value)
                {
                    // If System.StringComparer is not one of the 6 we recognize, comparerKey should be 0.
                    byte comparerKey;
                    StringComparerToByteMap.TryGetValue(value as System.Collections.Generic.IEqualityComparer<string> ?? System.Collections.Generic.EqualityComparer<string>.Default, out comparerKey);
                    writer.Write(comparerKey);
                }

                static public ScopeStruct       ScopeClone(this ScopeStruct value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeStruct)new StructColumnData(value).Clone().Value;
                }

                static public ScopeMap<K,V>     ScopeClone<K,V>(this ScopeMap<K,V> value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeMap<K,V>)new MapColumnData<K,V>(value).Clone().Value;
                }

                static public ScopeArray<T>     ScopeClone<T>(this ScopeArray<T> value, ReferenceHashTable<object> seenObject)
                {
                    return (ScopeArray<T>)new ArrayColumnData<T>(value).Clone().Value;
                }

                static public void Write<T>(BinaryValueWriter writer, ScopeArray<T> v)
                {
                    writer.Write(v);
                }

                static public void Read<T>(BinaryValueReader reader, out ScopeArray<T> v)
                {
                    reader.Read(out v);
                } 

                static public void Write<K,V>(BinaryValueWriter writer, ScopeMap<K,V> v)
                {
                    writer.Write(v);
                }

                static public void Read<K,V>(BinaryValueReader reader, out ScopeMap<K,V> v)
                {
                    reader.Read(out v);
                }                 
                

	}