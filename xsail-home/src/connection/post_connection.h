#ifndef __XSC_POST_CONNECTION_H__
#define __XSC_POST_CONNECTION_H__

__XSC_C_BEGIN_DECL

XSC_INTERNAL_VIEW(
    /**
     * Interface for post-connect objects which should be used to perform activities after a connection is established.
     */
    class PostConnectInterface { }
)
struct post_connect_op {
    XSC_INTERNAL_VIEW(
        // public:
        /**
         * The main method which is responsible for doing the PostConnect action
         * of the specific PostConnect object type.
         *
         * @param transport The transport to which the post connect is associated..
         *
         * @return A boolean to indicate that the post connect process has been successfully initiated
         */
        virtual bool doPostConnect(std::shared_ptr<HTTP2Transport> transport) = 0;
    )
    /**
     * The main method which is responsible for doing the PostConnect action
     * of the specific PostConnect object type.
     *
     * @param transport The transport to which the post connect is associated..
     *
     * @return A boolean to indicate that the post connect process has been successfully initiated
     */
    bool (*do_post_connect)(std::shared_ptr<HTTP2Transport> transport) = 0;

    XSC_INTERNAL_VIEW(
        /**
         * Handle notification that the connection has been lost.
         */
        virtual void onDisconnect() = 0;
    )
    /**
     * Handle notification that the connection has been lost.
     */
    void on_Disconnect(void *data);

    XSC_INTERNAL_VIEW(
        /**
         * PostConnectInterface destructor
         */
        virtual ~PostConnectInterface() = default;
    )

    /**
     * inheritance class host address
     */
    void *host;
};

__XSC_C_END_DECL

#endif /* end of include guard: __XSC_POST_CONNECTION_H__ */
/* vim: set ts=8 sw=8 noexpandtab: */
