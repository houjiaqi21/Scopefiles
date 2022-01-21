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

	public class Row_77740F60D5951C2A : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SepalLength", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SepalWidth", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("PetalLength", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("PetalWidth", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Name", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.DoubleColumnData s0_SepalLength;
		public ScopeRuntime.DoubleColumnData SepalLength
		{
			get { return s0_SepalLength; }
			set 
			{
				s0_SepalLength = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_SepalWidth;
		public ScopeRuntime.DoubleColumnData SepalWidth
		{
			get { return s0_SepalWidth; }
			set 
			{
				s0_SepalWidth = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_PetalLength;
		public ScopeRuntime.DoubleColumnData PetalLength
		{
			get { return s0_PetalLength; }
			set 
			{
				s0_PetalLength = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_PetalWidth;
		public ScopeRuntime.DoubleColumnData PetalWidth
		{
			get { return s0_PetalWidth; }
			set 
			{
				s0_PetalWidth = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Name;
		public ScopeRuntime.StringColumnData Name
		{
			get { return s0_Name; }
			set 
			{
				s0_Name = value;
				_columns[4] = value;
			}
		}
		public Row_77740F60D5951C2A(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_77740F60D5951C2A(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_77740F60D5951C2A() : base(BuildSchema(), BuildColumnData())
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
						s0_SepalLength = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 1:
					{
						s0_SepalWidth = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 2:
					{
						s0_PetalLength = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 3:
					{
						s0_PetalWidth = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 4:
					{
						s0_Name = (ScopeRuntime.StringColumnData)value;
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
			if (s0_Name.IsNull())
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
			s0_SepalLength.Serialize(writer);
			s0_SepalWidth.Serialize(writer);
			s0_PetalLength.Serialize(writer);
			s0_PetalWidth.Serialize(writer);
			if (!s0_Name.IsNull())
			{
				s0_Name.Serialize(writer);
			}
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_SepalLength.Deserialize(reader);
				s0_SepalWidth.Deserialize(reader);
				s0_PetalLength.Deserialize(reader);
				s0_PetalWidth.Deserialize(reader);
				s0_Name.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_SepalLength.Deserialize(reader);
				s0_SepalWidth.Deserialize(reader);
				s0_PetalLength.Deserialize(reader);
				s0_PetalWidth.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Name.Deserialize(reader);
				}
				else
				{
					s0_Name.SetNull();
				}
			}
		}
	}


	public class Row_54D58AA49E10FB30 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SepalLength_Mean", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("SepalWidth_Mean", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("PetalLength_Mean", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("PetalWidth_Mean", ScopeRuntime.ColumnDataType.Double, typeof(System.Double), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Name", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Count", ScopeRuntime.ColumnDataType.Integer, typeof(System.Int32), null, null),
		};

		ScopeRuntime.DoubleColumnData s0_SepalLength_Mean;
		public ScopeRuntime.DoubleColumnData SepalLength_Mean
		{
			get { return s0_SepalLength_Mean; }
			set 
			{
				s0_SepalLength_Mean = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_SepalWidth_Mean;
		public ScopeRuntime.DoubleColumnData SepalWidth_Mean
		{
			get { return s0_SepalWidth_Mean; }
			set 
			{
				s0_SepalWidth_Mean = value;
				_columns[1] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_PetalLength_Mean;
		public ScopeRuntime.DoubleColumnData PetalLength_Mean
		{
			get { return s0_PetalLength_Mean; }
			set 
			{
				s0_PetalLength_Mean = value;
				_columns[2] = value;
			}
		}
		ScopeRuntime.DoubleColumnData s0_PetalWidth_Mean;
		public ScopeRuntime.DoubleColumnData PetalWidth_Mean
		{
			get { return s0_PetalWidth_Mean; }
			set 
			{
				s0_PetalWidth_Mean = value;
				_columns[3] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Name;
		public ScopeRuntime.StringColumnData Name
		{
			get { return s0_Name; }
			set 
			{
				s0_Name = value;
				_columns[4] = value;
			}
		}
		ScopeRuntime.IntegerColumnData s0_Count;
		public ScopeRuntime.IntegerColumnData _Count_
		{
			get { return s0_Count; }
			set 
			{
				s0_Count = value;
				_columns[5] = value;
			}
		}
		public Row_54D58AA49E10FB30(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_54D58AA49E10FB30(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_54D58AA49E10FB30() : base(BuildSchema(), BuildColumnData())
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
						s0_SepalLength_Mean = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 1:
					{
						s0_SepalWidth_Mean = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 2:
					{
						s0_PetalLength_Mean = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 3:
					{
						s0_PetalWidth_Mean = (ScopeRuntime.DoubleColumnData)value;
						break;
					}
					case 4:
					{
						s0_Name = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 5:
					{
						s0_Count = (ScopeRuntime.IntegerColumnData)value;
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
			if (s0_Name.IsNull())
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
			s0_SepalLength_Mean.Serialize(writer);
			s0_SepalWidth_Mean.Serialize(writer);
			s0_PetalLength_Mean.Serialize(writer);
			s0_PetalWidth_Mean.Serialize(writer);
			if (!s0_Name.IsNull())
			{
				s0_Name.Serialize(writer);
			}
			s0_Count.Serialize(writer);
		}

		public override void Deserialize(BinaryReader reader)
		{
			byte[] ___masking___ = new byte[1];
			byte firstByte = reader.ReadByte();
			if (firstByte == 0)
			{
				s0_SepalLength_Mean.Deserialize(reader);
				s0_SepalWidth_Mean.Deserialize(reader);
				s0_PetalLength_Mean.Deserialize(reader);
				s0_PetalWidth_Mean.Deserialize(reader);
				s0_Name.Deserialize(reader);
				s0_Count.Deserialize(reader);
			}
			else
			{
				___masking___[0] = firstByte;
				s0_SepalLength_Mean.Deserialize(reader);
				s0_SepalWidth_Mean.Deserialize(reader);
				s0_PetalLength_Mean.Deserialize(reader);
				s0_PetalWidth_Mean.Deserialize(reader);
				if ((___masking___[0] & 2) != 2)
				{
					s0_Name.Deserialize(reader);
				}
				else
				{
					s0_Name.SetNull();
				}
				s0_Count.Deserialize(reader);
			}
		}
	}


	public class Row_7792A42DFDA6BCF3 : Row
	{
		private static readonly System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>[] _columnTable = 
		{
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("UserId", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Start", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Region", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Query", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Duration", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("Urls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
			new System.Tuple<string,ScopeRuntime.ColumnDataType,Type,ColumnDataCtor,string>("ClickedUrls", ScopeRuntime.ColumnDataType.String, typeof(System.String), null, null),
		};

		ScopeRuntime.StringColumnData s0_UserId;
		public ScopeRuntime.StringColumnData UserId
		{
			get { return s0_UserId; }
			set 
			{
				s0_UserId = value;
				_columns[0] = value;
			}
		}
		ScopeRuntime.StringColumnData s0_Start;
		public ScopeRuntime.StringColumnData Start
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
		ScopeRuntime.StringColumnData s0_Duration;
		public ScopeRuntime.StringColumnData Duration
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
		public Row_7792A42DFDA6BCF3(Schema schema, ColumnData[] columns) : base(schema, columns) { }
		public Row_7792A42DFDA6BCF3(Schema schema) : base(schema)
		{
			for (int i = 0; i < _columns.Length; ++i)
			{
				this[i] = _columns[i];
			}
		}
		public Row_7792A42DFDA6BCF3() : base(BuildSchema(), BuildColumnData())
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
						s0_UserId = (ScopeRuntime.StringColumnData)value;
						break;
					}
					case 1:
					{
						s0_Start = (ScopeRuntime.StringColumnData)value;
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
						s0_Duration = (ScopeRuntime.StringColumnData)value;
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
			if (s0_UserId.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 1);
			}
			if (s0_Start.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 2);
			}
			if (s0_Region.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 3);
			}
			if (s0_Query.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 4);
			}
			if (s0_Duration.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 5);
			}
			if (s0_Urls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 6);
			}
			if (s0_ClickedUrls.IsNull())
			{
				hasNull = true;
				___masking___[0] |= (byte)(1 << 7);
			}
			if (hasNull)
			{
				writer.Write(___masking___[0]);
			}
			else
			{
				writer.Write( (byte) 0);
			}
			if (!s0_UserId.IsNull())
			{
				s0_UserId.Serialize(writer);
			}
			if (!s0_Start.IsNull())
			{
				s0_Start.Serialize(writer);
			}
			if (!s0_Region.IsNull())
			{
				s0_Region.Serialize(writer);
			}
			if (!s0_Query.IsNull())
			{
				s0_Query.Serialize(writer);
			}
			if (!s0_Duration.IsNull())
			{
				s0_Duration.Serialize(writer);
			}
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
				if ((___masking___[0] & 2) != 2)
				{
					s0_UserId.Deserialize(reader);
				}
				else
				{
					s0_UserId.SetNull();
				}
				if ((___masking___[0] & 4) != 4)
				{
					s0_Start.Deserialize(reader);
				}
				else
				{
					s0_Start.SetNull();
				}
				if ((___masking___[0] & 8) != 8)
				{
					s0_Region.Deserialize(reader);
				}
				else
				{
					s0_Region.SetNull();
				}
				if ((___masking___[0] & 16) != 16)
				{
					s0_Query.Deserialize(reader);
				}
				else
				{
					s0_Query.SetNull();
				}
				if ((___masking___[0] & 32) != 32)
				{
					s0_Duration.Deserialize(reader);
				}
				else
				{
					s0_Duration.SetNull();
				}
				if ((___masking___[0] & 64) != 64)
				{
					s0_Urls.Deserialize(reader);
				}
				else
				{
					s0_Urls.SetNull();
				}
				if ((___masking___[0] & 128) != 128)
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