// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.ezored.core;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class ApplicationCore {
    public abstract void initialize(com.ezored.domain.InitializationData initializationData, com.ezored.domain.DeviceData deviceData);

    public abstract com.ezored.domain.InitializationData getInitializationData();

    public abstract com.ezored.domain.DeviceData getDeviceData();

    public abstract com.ezored.domain.Customer getCustomer();

    public abstract void setCustomer(com.ezored.domain.Customer customer);

    public abstract String getVersion();

    public static ApplicationCore shared()
    {
        return CppProxy.shared();
    }

    private static final class CppProxy extends ApplicationCore
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        @SuppressWarnings("deprecation")
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Override
        public void initialize(com.ezored.domain.InitializationData initializationData, com.ezored.domain.DeviceData deviceData)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_initialize(this.nativeRef, initializationData, deviceData);
        }
        private native void native_initialize(long _nativeRef, com.ezored.domain.InitializationData initializationData, com.ezored.domain.DeviceData deviceData);

        @Override
        public com.ezored.domain.InitializationData getInitializationData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getInitializationData(this.nativeRef);
        }
        private native com.ezored.domain.InitializationData native_getInitializationData(long _nativeRef);

        @Override
        public com.ezored.domain.DeviceData getDeviceData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getDeviceData(this.nativeRef);
        }
        private native com.ezored.domain.DeviceData native_getDeviceData(long _nativeRef);

        @Override
        public com.ezored.domain.Customer getCustomer()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getCustomer(this.nativeRef);
        }
        private native com.ezored.domain.Customer native_getCustomer(long _nativeRef);

        @Override
        public void setCustomer(com.ezored.domain.Customer customer)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setCustomer(this.nativeRef, customer);
        }
        private native void native_setCustomer(long _nativeRef, com.ezored.domain.Customer customer);

        @Override
        public String getVersion()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getVersion(this.nativeRef);
        }
        private native String native_getVersion(long _nativeRef);

        public static native ApplicationCore shared();
    }
}