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
public class MySum_Integer : Aggregate1<int, int>
{
    int sum = 0;



    public override void Initialize()
    {
        sum = 0;
    }



    public override void Add(int y)
    {
        sum += y;
    }



    public override int Finalize()
    {
        return sum;
    }
}

#endregion ==END USER CODE==

	public class Row_Region_String_Duration_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Region", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Duration", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.StringColumnData s0_Region;
		public ScopeRuntime.StringColumnData Region
		{
			get { return s0_Region; }
			set 
			{
				s0_Region = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Duration;
		public ScopeRuntime.IntegerColumnData Duration
		{
			get { return s0_Duration; }
			set 
			{
				s0_Duration = value;
				_columns[1] = value;
			}
		}
		public Row_Region_String_Duration_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Region_String_Duration_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Region_String_Duration_Integer() : base(BuildSchema(), BuildColumnData())
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
						s0_Region = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_Duration = (ScopeRuntime.IntegerColumnData)value;
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
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Region.IsNull())
			{
				s0_Region.Serialize(writer);
			}
			s0_Duration.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Region.Deserialize(reader);
				s0_Duration.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Region.Deserialize(reader);
				}
				else
				{
					s0_Region.SetNull();
				}
				s0_Duration.Deserialize(reader);
			}
		}
	}


	public class Row_Region_String_TotalDuration_Integer : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Region", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("TotalDuration", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.StringColumnData s0_Region;
		public ScopeRuntime.StringColumnData Region
		{
			get { return s0_Region; }
			set 
			{
				s0_Region = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_TotalDuration;
		public ScopeRuntime.IntegerColumnData TotalDuration
		{
			get { return s0_TotalDuration; }
			set 
			{
				s0_TotalDuration = value;
				_columns[1] = value;
			}
		}
		public Row_Region_String_TotalDuration_Integer(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_Region_String_TotalDuration_Integer(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_Region_String_TotalDuration_Integer() : base(BuildSchema(), BuildColumnData())
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
						s0_Region = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_TotalDuration = (ScopeRuntime.IntegerColumnData)value;
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
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_Region.IsNull())
			{
				s0_Region.Serialize(writer);
			}
			s0_TotalDuration.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_Region.Deserialize(reader);
				s0_TotalDuration.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				if ((___masking___[0] & 2) != 2)
				{
					s0_Region.Deserialize(reader);
				}
				else
				{
					s0_Region.SetNull();
				}
				s0_TotalDuration.Deserialize(reader);
			}
		}
	}


	public class ScopeGrouper_1 : Processor
	{
		//  Member variables used for aggregation
		byte[] Region;

		MySum_Integer s0_TotalDuration_accum;
		public override IEnumerable<Row> Process(RowSet s0_input, Row s0_outRow, string[] s0_args)
		{
			//  Scope variables
			Row_Region_String_TotalDuration_Integer s0_outputRow = (Row_Region_String_TotalDuration_Integer)s0_outRow;
			IEnumerator<Row> s0_enumerator = s0_input.Rows.GetEnumerator();
			
			if (s0_enumerator.MoveNext())
			{
				bool s0_alldone = false;
				Row_Region_String_TotalDuration_Integer s0_row = (Row_Region_String_TotalDuration_Integer)s0_enumerator.Current;
				for (;;)
				{
					Region = s0_row.Region.Binary;
					s0_TotalDuration_accum = new MySum_Integer();
					s0_TotalDuration_accum.Initialize();
					s0_TotalDuration_accum.Add(s0_row.TotalDuration.Integer);
					for (;;)
					{
						s0_alldone = !s0_enumerator.MoveNext();
						if (s0_alldone) break;
						s0_row = (Row_Region_String_TotalDuration_Integer)s0_enumerator.Current;
						if (ColumnDataComparer.Compare(Region, s0_row["Region"].Binary) != 0) 
							break;
						s0_TotalDuration_accum.Add(s0_row.TotalDuration.Integer);
					}  // end of all rows with this key
					s0_outputRow.Region.Set(Region);
					s0_outputRow.TotalDuration.Set(s0_TotalDuration_accum.Finalize());
					yield return s0_outputRow;
					if (s0_alldone) break;
				}  // end of all keys
			}
		}
		public override void MemoryLoadNotification(uint loadPercent, ulong availableBytes)
		{
			if (s0_TotalDuration_accum != null) { s0_TotalDuration_accum.MemoryLoadNotification(loadPercent, availableBytes); }
		}
	}


	public static System.Type[] __UdtTypeTable__ =
	{
		
	};

	public static class __OperatorFactory__
	{
		public static ScopeRuntime.Processor Create_Process_3()
		{
			return new ___Scope_Generated_Classes___.ScopeGrouper_1();
		}
		public static string Name_Process_3 = "___Scope_Generated_Classes___.ScopeGrouper_1";
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